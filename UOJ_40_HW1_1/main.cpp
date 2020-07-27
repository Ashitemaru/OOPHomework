#include "functions.h"
#include <iostream>
using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	#ifdef DEBUG
		cout << "value of a: " << a << ", value of b: " << b << endl;
		cout << "sum of a and b: "<<endl;
	#endif
	cout << sum(a, b) << endl;
	#ifdef DEBUG
		cout << "product of a and b: "<<endl;
	#endif
	cout << product(a, b) << endl;
	return 0;
}
