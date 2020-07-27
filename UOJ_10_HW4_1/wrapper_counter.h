#pragma once

class WrapperCounter {
	static map<string, int> count;
	static int total;
public:
	static string getUID(const string &type);
};
