// 实在懒得多文件了
// 将就着用吧

#include <iostream>
#include <map>
#include <string>
#include <vector>

#define MAX 0x3f3f3f

std::map<std::string, int> dict;

std::vector<int> indexOf(std::string s, std::string l) {
    int size = l.size();
    std::vector<int> indexes;
    for (int i = 0; i < s.size(); ++i) {
        if (s.substr(i, size) == l) indexes.push_back(i);
    }
    return indexes;
}

bool isNumber(std::string s) {
    for (char x: s)
        if (x < '0' || x > '9') return false;
    return true;
}

int handleCompare(std::string s) {
    if (s == "True") return MAX;
    if (s == "False") return -MAX;
    std::vector<int> separateBySpace = indexOf(s, " ");
    std::string op = s.substr(
        separateBySpace[0] + 1,
        separateBySpace[1] - separateBySpace[0] - 1
    );
    std::string a_str = s.substr(
        0,
        separateBySpace[0]
    );
    std::string b_str = s.substr(
        separateBySpace[1] + 1,
        MAX
    );

    int a = isNumber(a_str) ? stoi(a_str) : dict[a_str];
    int b = isNumber(b_str) ? stoi(b_str) : dict[b_str];

    if (op == ">") {
        return a > b ? MAX : -MAX;
    }
    else if (op == "<") {
        return a < b ? MAX : -MAX;
    }
    else if (op == ">=") {
        return a >= b ? MAX : -MAX;
    }
    else if (op == "<=") {
        return a <= b ? MAX : -MAX;
    }
    else if (op == "!=") {
        return a != b ? MAX : -MAX;
    }
    else if (op == "==") {
        return a == b ? MAX : -MAX;
    }
    else return -1;
}

int handleNot(std::string s) {
    if (s.substr(0, 3) == "not") return handleCompare(s.substr(4, MAX));
    else return handleCompare(s);
}

int handleAnd(std::string s) {
    std::vector<int> separateByAnd = indexOf(s, "and");
    if (separateByAnd.empty()) return handleNot(s);
    else {
        separateByAnd.insert(separateByAnd.begin(), -4);
        separateByAnd.push_back(MAX);
        for (int i = 0; i < separateByAnd.size() - 1; ++i) {
            std::string formula = s.substr(
                separateByAnd[i] + 4,
                separateByAnd[i + 1] - separateByAnd[i] - 5
            );
            if (handleNot(formula) == -MAX) return -MAX;
        }
        return MAX;
    }
}

int handleOr(std::string s) {
    if (!isNumber(s)) return std::stoi(s);

    std::vector<int> separateByOr = indexOf(s, "or");
    if (separateByOr.empty()) return handleAnd(s);
    else {
        separateByOr.insert(separateByOr.begin(), -3);
        separateByOr.push_back(MAX);
        for (int i = 0; i < separateByOr.size() - 1; ++i) {
            std::string formula = s.substr(
                separateByOr[i] + 3,
                separateByOr[i + 1] - separateByOr[i] - 4
            );
            if (handleAnd(formula) == MAX) return MAX;
        }
        return -MAX;
    }
}

void operateAssignment(std::string s) {
    int flag = 0;
    std::string valName = "";
    while (s[flag] != ' ') {
        valName.push_back(s[flag]);
        flag++;
    }
    flag += 3;
    std::string formula = s.substr(flag, MAX);
    dict[valName] = handleOr(formula);
}

void operatePrint(std::string s) {
    std::string formula = s.substr(6, MAX);
    int result = handleOr(formula);
    if (result == MAX) std::cout << "True\n";
    else if (result == -MAX) std::cout << "False\n";
    else std::cout << result << std::endl;
    return;
}

void operate(std::string s) {
    if (s.substr(0, 5) == "print") {
        operatePrint(s);
    } else {
        operateAssignment(s);
    }
    return;
}

int main() {
    std::string inputString;
    while (std::cin >> inputString) {
        operate(inputString);
    }
    return 0;
}