#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t,n,sum=0;
	cin >> t;
	while(t--)
	{
		cin >> n;
		if(n < 0)
		{
			sum += 0 - n;
		}
	}
	cout << sum << "\n";
}