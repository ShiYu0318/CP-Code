#include <iostream>
using namespace std;

int main()
{
	int t,n,x,min,max;
	cin >> t;
	for (int i=0;i<t;i++)
	{
		cin >> n;
		min=99;max=0;
		for(int j=0;j<n;j++)
		{
			cin >> x;
			if (x < min) min = x;
			if (x > max) max = x;
		}
		cout << (max - min) * 2 << "\n";
	}
}