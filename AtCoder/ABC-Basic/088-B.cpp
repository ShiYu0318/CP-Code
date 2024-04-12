#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define FORn(i,n) for(int i=0;i<n;++i)
#define rFOR(i,n) for(int i=n-1;i>=0;--i)
#define input(x,n) FOR(i,0,n) cin >> x[i];
#define dbg(x) cout << #x << "=" << x << ' ';
#define all(x) x.begin(),x.end()
#define int long long
#define nl cout << '\n';
#define Yn(x) cout << (x ? "Yes" : "No") << '\n';

signed main()
{
	int n; cin >> n;
	int t,s[2]={0};
	vector<int> v;
	FORn(i,n)
	{
		cin >> t;
		v.push_back(t);
	}
	sort(all(v));
	int now=0;
	rFOR(i,n)
	{
		s[now] += v[i];
		now = 1 - now;
	}
	cout << abs(s[0] - s[1]) << "\n";
}