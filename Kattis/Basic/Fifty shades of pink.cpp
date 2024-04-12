#include <bits/stdc++.h>
#define int long long
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

signed main()
{
	IO;
	int n,ans=0;
	string s,c;
	cin >> n;
	while(n--)
	{
		cin >> s;
		for(int j=0;j<s.size();j++)
		{
			if(s[j] >= 'A' && s[j] <= 'Z')
			{
				s[j] = s[j] + ('a' - 'A');
			}
		}
		for(int j=0;j<s.size()-3;j++)
		{
			c = s.substr(j,4);
			if(c == "rose" || c == "pink")
			{
				ans++;
				break;
			}
		}
	}
	if(ans == 0) cout << "I must watch Star Wars with my daughter\n";
	else cout << ans << "\n";
}