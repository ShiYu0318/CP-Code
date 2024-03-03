#include<bits/stdc++.h>
using namespace std;

signed main()
{
	int x=1,y=0,z=0;
	string s;cin >> s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i] == 'A') swap(x,y);
		else if(s[i] == 'B') swap(y,z);
		else swap(x,z);
	}
	if(x == 1) cout << 1 << "\n";
	else if(y == 1) cout << 2 << "\n";
	else cout << 3 << "\n";
}