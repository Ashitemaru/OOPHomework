#include <iostream>
#include <string>
#include <vector>

#define INF 0x3f3f3f

struct node {
    std::string name;
    int val;
    node(std::string n, int v): name(n), val(v) {};
};

std::vector<node> nodeList;

int getValueByName(std::string _name) {
    for (node x: nodeList)
        if (x.name == _name)
            return x.val;
    return INF;
}

void valueSetByName(std::string _name, int _val) {
    if (_val >= INF) return;
    for (node x: nodeList)
        if (x.name == _name) {
            x.val = _val;
            return;
        }
    nodeList.push_back(node(_name, _val));
    return;
}

bool isValueSet(std::string s) {
    for (char ch: s)
        if (ch == '=') return true;
    return false;
}

int stringToNumber(std::string s) {
    if (s == "") return 0;
    for (char ch: s)
        if (ch > '9' || ch < '0') return INF;
    return std::stoi(s);
}

int multiCalc(std::string s) {
    int result = 1;
    char operatorRegister = '*';
    std::string varName = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '*' || s[i] == '/') {
            int val = -1;
            if (stringToNumber(varName) != INF) val = stringToNumber(varName);
            else val = getValueByName(varName);
            if (val == INF) {
                std::cout << "error: undefined variable" << std::endl;
                return INF;
            }
            if (operatorRegister == '*') result *= val;
            else if(val == 0) {
                std::cout << "error: divided by zero" << std::endl;
                return INF;
            } else result /= val;
            operatorRegister = s[i];
            varName = "";
        } else {
            varName.push_back(s[i]);
        }
    }
    int outerVal = -1;
    if (stringToNumber(varName) != INF) outerVal = stringToNumber(varName);
    else outerVal = getValueByName(varName);
    if (outerVal == INF) {
        std::cout << "error: undefined variable" << std::endl;
        return INF;
    }
    if (operatorRegister == '*') result *= outerVal;
    else if(outerVal == 0) {
        std::cout << "error: divided by zero" << std::endl;
        return INF;
    } else result /= outerVal;
    return result;
}

int calc(std::string s) {
    int result = 0;
    char operatorRegister = '+';
    std::string multiString = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '+' || s[i] == '-') {
            int tmpResult = multiCalc(multiString);
            if (operatorRegister == '+') {
                if (tmpResult < INF) result += tmpResult;
                else return INF;
            } else {
                if (tmpResult < INF) result -= tmpResult;
                else return INF;
            }
            operatorRegister = s[i];
            multiString = "";
        } else {
            multiString.push_back(s[i]);
        }
    }
    int outerTmpResult = multiCalc(multiString);
    if (operatorRegister == '+') {
        if (outerTmpResult < INF) result += outerTmpResult;
        else return INF;
    } else {
        if (outerTmpResult < INF) result -= outerTmpResult;
        else return INF;
    }
    return result;
}

void valueSet(std::string s) {
    int index = -1;
    for (int i = 0; i < s.size(); i++)
        if (s[i] == '=') {
            index = i;
            break;
        }
    valueSetByName(
        s.substr(0, index),
        calc(s.substr(index + 1, s.size()))
    );
    return;
}

void operate(std::string s) {
    if (isValueSet(s)) valueSet(s);
    else if (calc(s) < INF) std::cout << calc(s) << std::endl;
    return;
}

int main() {
    std::string inputString;
    while (std::cin >> inputString) {
        operate(inputString);
    }
    return 0;
}