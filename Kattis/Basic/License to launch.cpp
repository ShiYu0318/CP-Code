#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,c=-1,ans=0;
	cin >> n;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
		if(c == -1 || a[i] < c) 
		{
			c = a[i];
			ans = i;
		}
	}
	cout << ans << '\n';
}