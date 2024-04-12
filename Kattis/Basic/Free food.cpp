#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,s,t,max=0,i,d[365]={0},ans=0;
	cin >> n;
	while(n--)
	{
		cin >> s >> t;
		if(t>max) max = t;
		for(i=s;i<=t;i++) d[i] = 1;
	}
	for(i=0;i<=max;i++)
	{
		if(d[i]!=0) ans++;
	}
	cout << ans << "\n";
}