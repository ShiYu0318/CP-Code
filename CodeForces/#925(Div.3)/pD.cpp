#include <bits/stdc++.h>
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define ull unsigned long long
#define pii pair<int,int>
#define vii vector<pii>
#define pq priority_queue
#define pq_min priority_queue<int,vector<int>,greater<int>> 
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
#define coutE(x) cout << x << '\n'
#define coutS(x) cout << x << ' '
#define dbg(x) cerr << #x << "=" << x << '\n';
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define rFOR(i,n) for(int i=n-1;i>=0;--i)
#define RPT(i,n) FOR(i,0,n)
#define input(x) for(auto &i : x) cin >> i
#define inputn(x,n) RPT(i,n) cin >> x[i] 
#define inputD(x,a,b) RPT(i,a) RPT(j,b) cin >> x[i][j]
#define output(x) for(auto i : x) cout << i << ' '
#define YN(x) cout << (x ? "YES" : "NO") << '\n'
#define Yn(x) cout << (x ? "Yes" : "No") << '\n'
#define yn(x) cout << (x ? "yes" : "no") << '\n'
#define islower(x) ((x) >= 'a' && (x) <= 'z')
#define isupper(x) ((x) >= 'A' && (x) <= 'Z')
#define isletter(x) (islower(x) || isupper(x))
#define SET(n) cout << fixed << setprecision(n)
#define nl(n) RPT(i,n) cout << '\n'
const double eps = 1e-8;
using namespace std;

// map 同餘性質

//==========================================================================================

void solve()
{
    int n,x,y; cin >> n >> x >> y;
    vector<int> v(n); input(v);
    sort(all(v)); output(v); nl(1);
    int ans = 0;
    RPT(i,n-1)
    {
        for(int j=n-1;j>i;--j)
        {
            if(v[i] + v[j] < x) break;
            if((v[i] + v[j]) % x == 0 && (v[i] - v[j]) % y == 0) ++ans;
        }
    }
    cout << ans << '\n';
}

signed main(void)
{
    ShiYu;
    int t; cin >> t;
    while(t--) solve();
}