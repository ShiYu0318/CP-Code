#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define FORn(i,n) for(int i=0;i<n;++i)
#define input(x,n) FOR(i,0,n) cin >> x[i];
#define dbg(x) cout << #x << "=" << x << ' ';
#define int long long
#define nl cout << "\n";
#define Yn(x) cout << (x ? "Yes" : "No") << '\n';

signed main()
{
	int n,m; cin >> n >> m;
	int tb[50] = {0},t;
	FORn(i,m*2)
	{
		cin >> t;
		tb[t-1]++;
	}
	FORn(i,n) cout << tb[i] << "\n";
}