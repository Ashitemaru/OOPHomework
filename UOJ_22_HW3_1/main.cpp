#include <iostream>
#include <cstdlib>
#include "Array.h"
#include "Node.h"

using namespace std;


void outputArray(Array& a, int len)
{
	for(int i = 0; i < len-1; i++)
	{
		cout << a[i] << " ";
	}
	cout << a[len-1] << endl;
}

void readArray(Array& a, int n)
{
	int pos, value;
	for(int i = 0; i < n; i++)
	{
		cin >> pos >> value;
		a[pos] = std::move(Node(value)); 
	}
}


void test()
{
	int len, k, n;
	int p, q, r;

	cin >> len;
	Array a(len);
	cin >> n; 
	readArray(a, n);

	cin >> k;
	for (int i=0;i<k;i++)
	{
		cin >> p >> q >> r;
		switch (p)
		{
			case 0:
				a.update(q, r);
				break;
			case 1:
				a.swap(q, r);
				break;
			case 2:
				a.insert(q, r);
				break;
			default:
				break;
		}
		outputArray(a, len);
	}
}

int main()
{
	freopen("example_in.txt","r",stdin);
	freopen("ouput.txt","w",stdout);
	int ref_ans;
	cin >> ref_ans;
	test();
	Node::outputResult(ref_ans);
	return 0;
}
