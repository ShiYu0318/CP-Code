#include<bits/stdc++.h>
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
#define mp(a,b) mack_pair(a,b)
#define FORn(i,n) for(int i=0;i<n;++i)
#define rFOR(i,n) for(int i=n-1;i>=0;--i)
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define coutE(x) cout << x << "\n"
#define coutS(x) cout << x << ' '
#define input(x) for(auto &i : x) cin >> i
#define output(x) for(auto &i : x) coutS(i)
#define inputD(x,a,b) FOR(i,0,a) FOR(j,0,b) cin >> x[i][j]
#define outputD(x,a,b) FOR(i,0,a) FOR(j,0,b) cin >> x[i][j]
#define DB(x) cerr << #x << " " << x << endl
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

void solve()
{	
	string s; cin >> s;
	FOR(i,1,9)
	{
		if(i == s[1] - '0') continue;
		else cout << s[0] + to_string(i) << "\n";
	}
	FOR(i,0,8)
	{
		if(i == s[0] - 'a') continue;
		cout << (char)('a'+ i) << s[1] << "\n";
	}
}

signed main(void)
{
	ShiYu;
	int t; cin >> t;
	while(t--) solve();
}