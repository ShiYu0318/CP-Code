#include <bits/stdc++.h>
using namespace std;

void star(int n)
{
    for(int i=1;i<=n;i++)
	{
		for(int j=n-i;j>0;j--)
		{
			cout << ' ';
		}
		for(int j=i*2;j>1;j--)
		{
			cout << "*";
		}
		cout << '\n';
	}
}

signed main()
{
    int n,t; cin >> t;
    while(t--)
    {
        cin >> n;
        star(n);
    }
}