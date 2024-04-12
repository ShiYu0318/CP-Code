#include <bits/stdc++.h>
#define ShiYu ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define FOR(i,n) for(int i=0;i<n;++i)
#define input(x) for(auto &i : x) cin >> i
#define output(x) for(auto &i : x) coutS(i)
#define YN(x) cout << (x ? "YES" : "NO") << "\n"
#define nl cout << "\n"
using namespace std;

void solve()
{	
    int t; cin >> t;
    while(t--)
    {
        int n,k; cin >> n >> k;
        string s; cin >> s;
        int ans = 0;
        FOR(i,n)
        {
            if(s[i]=='B')
            {
                ans++;
                i += k-1;
            }
        }
        cout << ans << "\n";
    }
}

signed main()
{
	ShiYu;
	solve();
	return 0;
}