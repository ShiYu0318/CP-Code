#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
// Type --------------------------------------------------------------------
#define int long long
#define ull unsigned long long
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define MM mx = INT_MIN, mi = INT_MAX
#define pq priority_queue
#define pq_min priority_queue<int,vector<int>,greater<int>>
// Simple ------------------------------------------------------------------
#define F first
#define S second
#define MP make_pair
#define EB emplace_back
// Function ----------------------------------------------------------------
#define SZ(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define sortall(x) sort(x.begin(), x.end())
#define remax(a,b) a = (a > b ? a : b)
#define remin(a,b) a = (a < b ? a : b)
#define islower(x) ('a' <= x && x <= 'z')
#define isupper(x) ('A' <= x && x <= 'Z')
#define isletter(x) (islower(x) || isupper(x))
#define SET(n) cout << fixed << setprecision(n)
// Loop --------------------------------------------------------------------
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
// Loop I/O -----------------------------------------------------------------
#define input(x) for(auto &i:x) cin >> i
#define inputN(x,n) RPT(i,n) cin >> x[i]
#define input2(x,a,b) RPT(i,a) RPT(j,b) cin >> x[i][j]
#define outputN(x,n) RPT(i,n) cout << x[i] << " \n"[i == n-1];
#define output(x) outputN(x,SZ(x))
#define output2(x,a,b) RPT(i,a) RPT(j,b) cout << x[i][j] << " \n"[j == b-1]
#define outputP(x) for(auto i:x) cout << i.F << " " << i.S << '\n';
// YN ----------------------------------------------------------------------
#define YN(x) cout << (x ? "YES" : "NO") << '\n'
#define Yn(x) cout << (x ? "Yes" : "No") << '\n'
#define yn(x) cout << (x ? "yes" : "no") << '\n'
// const -------------------------------------------------------------------
const double eps = 1e-8;

// ==========================================================================================
// RE-SOLVE
// ==========================================================================================

const int MX = 1000000;
int spf[MX + 1];
ull H[MX + 1];

void init()
{
	mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
	FOR(i, 2, MX + 1)
		if (!spf[i])
			for (int j = i; j <= MX; j += i)
				if (!spf[j]) spf[j] = i;
	FOR(i, 2, MX + 1) if (spf[i] == i) H[i] = rng();
}

// x 中 指數為奇數 的質數, 其隨機值的 XOR
ull getHash(int x)
{
	ull h = 0;
	while (x > 1)
	{
		int p = spf[x], c = 0;
		while (x % p == 0) x /= p, c++;
		if (c & 1) h ^= H[p];
	}
	return h;
}

void solve()
{
	int unblended = 0;
	int n; cin >> n;
	vector<ull> h(n), pre(n);
	ull cur = 0;
	RPT(i, n)
	{
		int x; cin >> x;
		h[i] = getHash(x);
		cur ^= h[i];
		pre[i] = cur;
	}
	vector<ull> sp_ = pre;
	sortall(sp_);
	int ans = 0;
	RPT(i, n)
	{
		auto r = equal_range(all(sp_), h[i]);
		ans += r.S - r.F;
	}
	coutN(ans);
}

signed main()
{
	ShiYu;
	init();
	int t = 1;
	cin >> t; // hide it when one case
	while(t--) solve();
}