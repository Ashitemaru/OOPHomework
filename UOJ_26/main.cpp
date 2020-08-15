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
        int x, y;
		string act;
        cin >> act;
        if(act == "insert")
        {
			A item;
            cin >> x >> y >> item;
            cont->insert(make_pair(x,y), item);
        }
        else
        {
            cin >> x >> y;
            A* result = cont->find(make_pair(x,y));
            if (result==NULL)
                cout << "Not found" << endl;
            else
                cout << *result << endl;
        }
    }
}

template <class A>
void start(const string &base)
{
    BasicContainer<A>* cont;
    if(base == "vector")
        cont = new Container<A, vector<A> >;
    else if(base == "map")
        cont = new Container<A, map<Pos, A> >;
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
