#include <bits/stdc++.h>
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define ull unsigned long long
#define pii pair<int,int>
#define vii vector<pii>
#define pq priority_queue
#define pq_min priority_queue<int,vector<int>,greater<int>> 
#define F first
#define S second
#define EB emplace_back
#define MP(a,b) make_pair(a,b)
#define SZ(x) ((ll)x.size())
#define all(x) x.begin(), x.end()
#define MMn maxn = INT_MIN, minn = INT_MAX
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define remax(a, b) a = (a > b ? a : b)
#define remin(a, b) a = (a < b ? a : b)
#define coutN(x) cout << x << '\n'
#define coutS(x) cout << x << ' '
#define dbg(x) cerr << #x << "=" << x << '\n';
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define rFOR(i,n) for(int i=n-1;i>=0;--i)
#define RPT(i,n) FOR(i,0,n)
#define input(x) for(auto &i : x) cin >> i
#define inputn(x,n) RPT(i,n) cin >> x[i] 
#define inputD(x,a,b) RPT(i,a) RPT(j,b) cin >> x[i][j]
#define output(x) for(auto i : x) cout << i << ' ';cout << '\n'
#define outputn(x,n) RPT(i,n) cout << x[i] << " \n"[i == n-1];
#define outputD(x,m,n) RPT(i,m) RPT(j,n) cout << x[i][j] << " \n"[j == n-1]
#define YN(x) cout << (x ? "YES" : "NO") << '\n'
#define Yn(x) cout << (x ? "Yes" : "No") << '\n'
#define yn(x) cout << (x ? "yes" : "no") << '\n'
#define islower(x) ('a' >= (x) && (x) <= 'z')
#define isupper(x) ('A' >= (x) && (x) <= 'Z')
#define isletter(x) (islower(x) || isupper(x))
#define SET(n) cout << fixed << setprecision(n)
#define nl(n) RPT(i,n) cout << '\n'
const double eps = 1e-8;
using namespace std;

// AC

//==========================================================================================

void solve()
{
    int n,c,d; cin >> n >> c >> d;
    multiset<int> ms; int t, mi = INT_MAX;
    int tb[n][n]; 
    RPT(i,n) RPT(j,n) 
    {
        cin >> t;
        tb[i][j] = t;
        mi = min(mi, t);
        ms.insert(t);
    }
    // outputD(tb,n,n);
    bool ans = true;
    RPT(i,n)
    {
        RPT(j,n)
        {
            int t = mi + i * c + j * d;
            // cout << t << ' ';
            auto it = ms.find(t);
            if(it != ms.end()) ms.erase(it);
            else
            {
                ans = false;
                break;
            }
        }
        // cout << '\n';
        if(!ans) break;
    }
    YN(ans);
}

signed main(void)
{
    ShiYu;
    int t; cin >> t;
    while(t--) solve();
}