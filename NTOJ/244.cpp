#include <bits/stdc++.h>
using namespace std;

signed main()
{
	int n;
	string s;
	cin >> n >> s;
	for(int i=0;i<n;i++)
	{
		if(s[i] >= 'A' && s[i] <= 'Z') s[i] = char(s[i] + ('a'-'A'));
		else s[i] = char(s[i] - ('a'-'A'));
	}
	cout << s << "\n";
}