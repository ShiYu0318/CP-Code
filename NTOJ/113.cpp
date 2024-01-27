#include<bits/stdc++.h>
using namespace std;

signed main()
{
	int n,x;
	string s;
	char m;
	cin >> n >> s >> m;
	for(int i=0;i<n;i++)
	{
		if(s[i] == 'P') x = i;
	}
	if(m == 'L')
	{
		s[x] = '.';
		s[x-1] = 'P';
	}
	if(m == 'R')
	{
		s[x] = '.';
		s[x+1] = 'P';
	}
	cout << s << "\n";
}