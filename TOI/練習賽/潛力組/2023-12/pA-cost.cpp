// 遞迴
#include <bits/stdc++.h>
#define ShiYu ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
#define ull unsigned ll
#define int ll
#define vii vector<pair<int, int>>
#define pq priority_queue
#define pq_min priority_queue < int, vector<int>, greater<int> > 
#define MMn maxn = INT_MIN, minn = INT_MAX
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define remax(a, b) a = (a > b ? a : b)
#define remin(a, b) a = (a < b ? a : b)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(), x.end()
#define mp(a,b) make_pair(a,b)
#define dbg(x) cerr << #x << "=" << x << endl
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define FORn(i,n) for(int i=0;i<n;++i)
#define rFOR(i,n) for(int i=n-1;i>=0;--i)
#define coutE(x) cout << x << "\n"
#define coutS(x) cout << x << ' '
#define input(x) for(auto &i : x) cin >> i
#define output(x) for(auto &i : x) dbg(i)
#define inputD(x,a,b) FOR(i,0,a) FOR(j,0,b) cin >> x[i][j]
#define YN(x) cout << (x ? "YES" : "NO") << "\n"
#define Yn(x) cout << (x ? "Yes" : "No") << "\n"
#define yn(x) cout << (x ? "yes" : "no") << "\n"
#define SET(n) cout << fixed << setprecision(n)
#define F first
#define S second
#define pb push_back
#define nl cout << "\n"
const double eps = 1e-8;
using namespace std;

//==========================================================================================

vector<vii> v;
int p[1000];

int get_cost(int s, int q)
{
    vii vt;
    if(!v[s].empty()) vt = v[s];
    int sum = 0;
    FORn(i,vt.size())
    {
        sum += get_cost(vt[i].F-1, vt[i].S);
    }
    return (sum + p[s]) * q;
}

void solve()
{	
    int n; cin >> n;
    FORn(i,n) cin >> p[i];
    int m,s,a;
    FORn(i,n)
    {
        vii vt;
        cin >> m;
        while(m--)
        {
            cin >> s >> a;
            vt.pb(mp(s,a));
        }
        v.pb(vt);
    }

    FORn(i,n) cout << get_cost(i,1) << "\n";
}

signed main(void)
{
	ShiYu
	solve();
}