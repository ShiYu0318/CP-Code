#include <iostream>
using namespace std;

int main()
{
	int n,tmp,m0=0,m1=0,m2=0;
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		cin >> tmp;
		if (tmp % 3 == 0) m0++;
		else if (tmp % 3 == 1) m1++;
		else m2++;
	}
	cout << m0 << " " << m1 << " " << m2 << "\n";
}