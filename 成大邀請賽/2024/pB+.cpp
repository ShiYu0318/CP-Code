#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
// type --------------------------------------------------------------------
#define int long long
#define ull unsigned long long
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define MM mx = INT_MIN, mi = INT_MAX
#define pq priority_queue
#define pq_min priority_queue<int,vector<int>,greater<int>>
// simple ------------------------------------------------------------------
#define F first
#define S second
#define MP make_pair
#define EB emplace_back
// function ----------------------------------------------------------------
#define SZ(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define sortall(x) sort(x.begin(), x.end())
#define remax(a,b) a = (a > b ? a : b)
#define remin(a,b) a = (a < b ? a : b)
#define islower(x) ('a' >= x && x <= 'z')
#define isupper(x) ('A' >= x && x <= 'Z')
#define isletter(x) (islower(x) || isupper(x))
#define SET(n) cout << fixed << setprecision(n)
// loop --------------------------------------------------------------------
#define RPT(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define rFOR(i,n) for(int i=n-1; i>=0; --i)
#define forit(it,x) for (auto it = x.begin(); it != x.end(); ++it)
// I/O ----------------------------------------------------------------------
#define sp << ' ' << 
#define nl cout << '\n'
#define coutS(x) cout << x << ' '
#define coutN(x) cout << x << '\n'
#define NL(n) RPT(i,n) cout << '\n'
#define dbg(x) cerr << #x << " = " << x << '\n';
// loop I/O -----------------------------------------------------------------
#define input(x) for(auto &i:x) cin >> i
#define inputN(x,n) RPT(i,n) cin >> x[i]
#define inputD(x,a,b) RPT(i,a) RPT(j,b) cin >> x[i][j]
#define output(x) for(auto i:x) cout << i << ' '; cout << '\n'
#define outputN(x,n) RPT(i,n) cout << x[i] << " \n"[i == n-1];
#define outputD(x,a,b) RPT(i,a) RPT(j,b) cout << x[i][j] << " \n"[j == n-1]
// YN ----------------------------------------------------------------------
#define YN(x) cout << (x ? "YES" : "NO") << '\n'
#define Yn(x) cout << (x ? "Yes" : "No") << '\n'
#define yn(x) cout << (x ? "yes" : "no") << '\n'
// const -------------------------------------------------------------------
const double eps = 1e-8;

// ==========================================================================================
// 
// ==========================================================================================

void solve()
{
    int n; cin >> n;
    vi h(n+1), pf(n+2), w(n);
    pf[0] = 0;
    RPT(i,n+1)
    {
        cin >> h[i];
        pf[i+1] = pf[i] + h[i];
    }
    // output(pf);
    input(w);
    int q; cin >> q;
    int d,e,m,l;
    RPT(i,q)
    {
        cin >> d >> e >> m >> l;
        int ans = -1;
        RPT(j,n)
        {
            if(l > w[j])
            {
                ans = j;
                break;
            }
            if(d == 1) e = e + m * m * (h[j] - h[j+1]);
            else e = e + m * (h[j] - h[j+1]);
            // cout << "j=" << j+1 << " e=" << e << '\n';
            if(e < 0)
            {
                ans = j;
                break;
            }
        }
        if(ans == -1) cout << "Yes\n";
        else cout << "No\n" << ans + 1 << '\n';
    }
}

signed main()
{
    ShiYu;
    int t = 1;
    // cin >> t; // hide it when one case
    while(t--) solve();
}