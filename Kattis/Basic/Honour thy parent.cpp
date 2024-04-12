#include <bits/stdc++.h>
#define int long long
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0)
using namespace std;

signed main()
{
	ShiYu;
	string y,p,ans;
	cin >> y >> p;
	char c = y[y.size()-1];
	if(c == 'e') ans = y + 'x' + p;
	else if(c == 'a' || c == 'i' || c == 'o' || c == 'u')
	{
		y.resize(y.size()-1);
		ans = y + "ex" + p;
	}
	else if(y[y.size()-2] == 'e' && c == 'x') ans = y + p;
	else ans = y + "ex" + p;
	cout << ans << "\n";
}