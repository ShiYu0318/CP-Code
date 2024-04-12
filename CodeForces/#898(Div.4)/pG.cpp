#include <bits/stdc++.h>
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
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
        string s; cin >> s;
        int ans=0;
        while(1)
        {
            bool c = false;
            FOR(i,s.size()-1)
            {
                if(s[i] == 'A' && s[i+1] == 'B')
                {
                    s[i] = 'B';
                    s[i+1] = 'C';
                    ans++;
                    c = true;
                }
                if(s[i] == 'B' && s[i+1] == 'A')
                {
                    s[i] = 'C';
                    s[i+1] = 'B';
                    ans++;
                    c = true;
                }
                if(c) break;
            }
            if(!c) break;
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