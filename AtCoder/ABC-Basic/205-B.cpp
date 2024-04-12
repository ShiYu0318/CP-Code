#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define input(x,n) FOR(i,0,n) cin >> x[i];
#define dbg(x) cout << #x << "=" << x << ' ';
#define int long long
#define nl cout << "\n";
#define Yn(x) cout << (x ? "Yes" : "No") << '\n';

signed main()
{
	int n; cin >> n;
	int a[1000]; input(a,n);
	sort(a, a + n);
	bool ans = true;
	FOR(i,0,n)
	{
		if(a[i] != i+1)
		{
			ans = false;
			break;
		}
	}
	Yn(ans);
}