#include <bits/stdc++.h>
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define ull unsigned ll
#define int ll
#define vii vector< pair<int, int> >
#define pq priority_queue
#define pq_min priority_queue < int, vector<int>, greater<int> > 
#define F first
#define S second
#define pb push_back
#define mp(a,b) make_pair(a,b)
#define sz(x) ((ll)x.size())
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
#define FORn(i,n) for(int i=0;i<n;++i)
#define rFOR(i,n) for(int i=n-1;i>=0;--i)
#define input(x) for(auto &i : x) cin >> i
#define inputn(x,n) FORn(i,n) cin >> x[i] 
#define inputD(x,a,b) FORn(i,a) FORn(j,b) cin >> x[i][j]
#define output(x) for(auto &i : x) dbg(i)
#define YN(x) cout << (x ? "YES" : "NO") << "\n"
#define Yn(x) cout << (x ? "Yes" : "No") << '\n'
#define yn(x) cout << (x ? "yes" : "no") << "\n"
#define SET(n) cout << fixed << setprecision(n)
#define nl(n) FORn(i,n) cout << '\n'
const double eps = 1e-8;
using namespace std;

//==========================================================================================

void solve()
{
	int t; cin >> t;
	int a,b,c;
	while(t--)
	{
		cin >> a >> b >> c;
		if(a == b) cout << c << "\n";
		else if(a == c) cout << b << "\n";
		else cout << a << "\n";
	}
}

signed main(void)
{
	ShiYu;
	solve();
}