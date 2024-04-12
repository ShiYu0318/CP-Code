#include <bits/stdc++.h>
using namespace std;
// 這題要注意不夠減要繞回Z
signed main()
{
	int n;
	string s;
	cin >> n >> s;
	for(int i=0;i<s.size();i++)
	{
		if(char(s[i] - n) < 'A')
		{
			s[i] = char('Z' - (n - (s[i] - 'A')) + 1);
		}
		else s[i] = char(s[i] - n);
	}
	cout << s << '\n';
}