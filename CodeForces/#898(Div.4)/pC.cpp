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
    int n; cin >> n;
    while(n--)
    {
        string s[10];
        int sum = 0;
        FOR(i,10) cin >> s[i];
        FOR(i,10)
        {
            FOR(j,10)
            {
                if(s[i][j]=='X')
                {
                    sum++;
                    if(0<i && i<9 && 0<j && j<9) sum++;
                    if(1<i && i<8 && 1<j && j<8) sum++;
                    if(2<i && i<7 && 2<j && j<7) sum++;
                    if(3<i && i<6 && 3<j && j<6) sum++;
                }
            }
        }
        cout << sum << "\n";
    }
}

signed main()
{
	ShiYu;
	solve();
	return 0;
}