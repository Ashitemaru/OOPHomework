#include "Container.h"
#include <set>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

template<class A>
void work(BasicContainer<A>* cont)
{	
	int n;
    cin >> n;
    while(n--)
    {
		string act;
        cin >> act;
        if(act == "insert")
        {
			A item;
            cin >> item;
            cont->insert(item);
        }
        else
        {
			int k;
            cin >> k;
            cout << cont->find(k) << endl;
        }
    }
}

template <class A>
void start(const string &base)
{
    BasicContainer<A>* cont;
    if(base == "vector")
        cont = new Container<A, vector<A>>;
    else if(base == "multiset")
        cont = new Container<A, multiset<A>>;
    work(cont);
    delete cont;
}

int main()
{
    string base, type;
    cin >> base >> type;
	
    if(type == "int")
        start<int>(base);
    else if(type == "string")
        start<string>(base);		
	
	return 0;
}
