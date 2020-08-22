#include <iostream>
#include <string>
#include "Value.h"
#include "Operator.h"
#include "plus.h"
#include "minus.h"
#include "multi.h"
#include "nodes.h"
int n;
Value *v[100001];
std::string s;
int main()
{
    std::cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        std::cin >> s;
        if(s == "Constant")
        {
            int val;
            std::cin >> val;
            v[i] = new Constant(val);
        }
        else if(s == "Plus")
        {
            int a, b;
            std::cin >> a >> b;
            v[i] = new Plus(v[a], v[b]);
        }
        else if(s == "Sub")
        {
            int a, b;
            std::cin >> a >> b;
            v[i] = new Minus(v[a], v[b]);
        }
        else if(s == "Multiply")
        {
            int a, b;
            std::cin >> a >> b;
            v[i] = new Multi(v[a], v[b]);
        }
        else if(s == "Print")
        {
            int n;
            std::cin >> n;
            v[i] = new Print(v[n]);
            std::cout << v[i]->calc() << std::endl;
        }
        else if(s == "Modify")
        {
            int n, val;
        	std::cin >> n >> val;
            v[i] = new Modify(v[n], val);
            dynamic_cast<Constant*>(v[n])->changeVal(val);
        }
    }
	return 0;
}
