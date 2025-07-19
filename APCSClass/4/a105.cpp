#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define F first
#define S second
#define EB emplace_back
#define endl '\n'
#define nl cout << '\n'
#define SZ(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define RPT(i,n) for(int i=0; i<=n; ++i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define rFOR(i,n) for(int i=n-1; i>=0; --i)
#define input(x) for(auto &i:x) cin >> i
#define output(x) for(auto i:x) cout << i << ' '; nl
#define outputN(x,n) RPT(i,n) cout << x[i] << " \n"[i == n-1];
#define Yn(x) cout << (x ? "Yes" : "No") << '\n';

const int N = 505;
bool tb[N][N] = {0};

signed main()
{
    ShiYu;
    int m,n; cin >> m >> n;
    int q; cin >> q;
    while(q--)
    {
        int a,b,c,d; cin >> a >> b >> c >> d;
        if(a == c)
        {
            if(b > d) swap(b,d);
            FOR(i,b,d+1) tb[a][i] = true;
        }
        else if(b == d)
        {
            if(a > c) swap(a,c);
            FOR(i,a,c+1) tb[i][b] = true;
        }
        else
        {
            if(a > c) {swap(a,c); swap(b,d);}
            if(b < d) for(int i = a, j = b; i <= c; ++i, ++j) tb[i][j] = true;
            else for(int i = a, j = b; i <= c; ++i, --j) tb[i][j] = true;
        }
        // RPT(i,n) cout << i << " \n"[i == n];
        // RPT(i,m) RPT(j,n) cout << tb[i][j] << " \n"[j == n];
        // cout << "\n\n";
    }
    int ans = 0;
    RPT(i,m) RPT(j,n) ans += tb[i][j];
    cout << ans << endl;
}