#include "wrapper_counter.h"
using namespace std;

class AbstractWrapper {
	string uid;
public:
	AbstractWrapper(string type) { 
		uid = WrapperCounter::getUID(type); 
	}
	virtual ~AbstractWrapper(){};
	virtual string type() = 0;
	virtual string to_string() = 0;
	friend ostream &operator <<(ostream &out, AbstractWrapper *w) {
		return out << w->uid << ": " << w->to_string();
	}
};

class IntegerWrapper : public AbstractWrapper {
	int *ptr;
public:
	IntegerWrapper(int *ptr): AbstractWrapper("int"), ptr(ptr) {};
	virtual ~IntegerWrapper() override { 
		delete ptr; 
	}
	virtual string type() override { 
		return "int"; 
	}
	virtual string to_string() override {
		return std::to_string(*ptr);
	}
};

class StringWrapper : public AbstractWrapper {
protected:
	char *ptr;
	int len;
public:
	StringWrapper(char *ptr, int len, string type="string"): AbstractWrapper(type), ptr(ptr), len(len) {};
	virtual ~StringWrapper() override { 
		delete[] ptr; 
	}
	virtual string type() override { 
		return "string"; 
	}
	virtual string to_string() override {
		return string(ptr, len);
	}
	int length() { 
		return len; 
	}
};

class ChineseStringWrapper : public StringWrapper {
	// 用三个char表示一个汉字
public:
	ChineseStringWrapper(char *ptr, int len): StringWrapper(ptr, len, "chineseString") {};
	virtual ~ChineseStringWrapper() override {};
	virtual string type() override { 
		return "chineseString"; 
	}
	virtual string to_string() override { 
		return string(ptr,len); 
	}
	int length(bool rawChars = true) {
		// 如果rawChars为false，则返回中文字符数；否则返回实际char数组长度
		if (rawChars) return len;
		else return len / 3;
	}
};