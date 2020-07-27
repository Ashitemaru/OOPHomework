#include <iostream>
#include <cstring>
#include <string>
#include <map>

using namespace std;

#include "wrapper.h"
#include "wrapper_counter.h"
#include "pointer.h"

typedef void (*Fun)(void);

string WrapperCounter::getUID(const string &type) {
	int id = count[type];
	string uid = type + to_string(id) + "_" + to_string(total);
	count[type] += 1;
	total += 1;
	return uid;
}

map<string, int> WrapperCounter::count;
int WrapperCounter::total = 0;

int getLength(AbstractWrapper &x) {
	if (x.type() == "string") {
		return dynamic_cast<StringWrapper &>(x).length();
	} else if (x.type() == "chineseString") {
		return dynamic_cast<ChineseStringWrapper &>(x).length();
	} else {
		return -1;
	}
}

int main() {

	int *ip1 = new int(8263), *ip2 = new int(2317);

	char *cp = new char[20];
	int length = 15;
	for (int i = 0; i < length; ++i)
		cp[i] = static_cast<char>('a' + i);
	cp[length] = '\0';
	// cerr << "char *p" << endl;

	char *ccp = new char[20];
	strcpy(ccp, "这是一句中文");
	// cerr << "char *cp" << endl;

	auto *iw1 = new IntegerWrapper(ip1), *iw2 = new IntegerWrapper(ip2);
	// cerr << "*iw" << endl;
	auto *sw = new StringWrapper(cp, length);
	// cerr << "*sw" << endl;
	auto *csw = new ChineseStringWrapper(ccp, strlen(ccp));
	// cerr << "*csw" << endl;

	cout << "Length of *iw1: " << getLength(*iw1) << endl;
	cout << "Length of *iw2: " << getLength(*iw2) << endl;
	cout << "Length of *sw: " << getLength(*sw) << endl;
	cout << "Length of *csw: " << getLength(*csw) << endl;

	cout << "Actual length of *csw: " << csw->length(false) << endl;

	const int n_wrappers = 4;
	AbstractWrapper *aw[n_wrappers] = {iw1, iw2, sw, csw};
	for (int i = n_wrappers - 1; i >= 0; --i)
		cout << aw[i] << endl;
	for (int i = 0; i < n_wrappers; ++i)
		delete aw[i];

	if (!AllocManager::check_released(ip1))
		cout << "memory leak: *ip1 was not released" << endl;
	if (!AllocManager::check_released(ip2))
		cout << "memory leak: *ip2 was not released" << endl;
	if (!AllocManager::check_released(cp))
		cout << "memory leak: *cp was not released" << endl;
	if (!AllocManager::check_released(ccp))
		cout << "memory leak: *ccp was not released" << endl;

	return 0;
}
