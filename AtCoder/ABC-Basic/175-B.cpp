#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define input(x,n) FOR(i,0,n) cin >> x[i];
#define dbg(x) cout << #x << "=" << x << ' ';
#define int long long
#define nl cout << "\n";

signed main()
{
	int n; cin >> n;
	int l[100]; input(l,n);
	sort(l, l+n);
	int ans = 0;
	FOR(i,0,n)
	{
		FOR(j,i+1,n)
		{
			if(l[i] == l[j]) continue;
			FOR(k,j+1,n)
			{
				if(l[i] == l[k] || l[j] == l[k]) continue;
				if(l[i] + l[j] > l[k])
				{
					ans++;
				}
				
			}
		}
	}
	cout << ans << "\n";
}