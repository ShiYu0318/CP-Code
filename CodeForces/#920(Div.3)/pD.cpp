#include <bits/stdc++.h>
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define ull unsigned ll
#define int ll
#define pii pair< int, int >
#define vii vector< pii >
#define pq priority_queue
#define pq_min priority_queue < int, vector<int>, greater<int> > 
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
#define coutE(x) cout << x << "\n"
#define coutS(x) cout << x << ' '
#define dbg(x) cerr << #x << "=" << x << "\n";
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define rFOR(i,n) for(int i=n-1;i>=0;--i)
#define RPT(i,n) FOR(i,0,n)
#define input(x) for(auto &i : x) cin >> i
#define inputn(x,n) RPT(i,n) cin >> x[i] 
#define inputD(x,a,b) RPT(i,a) RPT(j,b) cin >> x[i][j]
#define output(x) for(auto &i : x) cout << i << ' ';
#define YN(x) cout << (x ? "YES" : "NO") << "\n"
#define Yn(x) cout << (x ? "Yes" : "No") << '\n'
#define yn(x) cout << (x ? "yes" : "no") << "\n"
#define SET(n) cout << fixed << setprecision(n)
#define nl(n) RPT(i,n) cout << "\n"
const double eps = 1e-8;
using namespace std;

//==========================================================================================

void solve()
{
    int a,b; cin >> a >> b;
    vector<int> x(a),y(b);
    input(x); input(y);
    sort(all(x));sort(all(y));

    output(x);cout << "\n";
    output(y);cout << "\n\n";

    int sz = y.size(), ans = 0;
    int i=0,j = sz - 1;
    rFOR(k,x.size())
    {
        if(abs(x[k] - y[i]) > abs(x[k] - y[j]))
        {
            ans += abs(x[k] - y[i]);
            ++i;
        }
        else
        {
            ans += abs(x[k] - y[j]);
            --j;
        }
    }
    cout << ans << "\n";
    
}

signed main(void)
{
	ShiYu;
	int t; cin >> t;
	while(t--) solve();
}