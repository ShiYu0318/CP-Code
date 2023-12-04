#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define input(x,n) FOR(i,0,n) cin >> x[i];
#define dbg(x) cout << #x << "=" << x << " ";
#define int long long
#define nl cout << "\n";
#define Yn(x) cout << (x ? "Yes" : "No") << "\n";

int a[200005];

signed main()
{
	int n; cin >> n;
	input(a,n-1);
	sort(a, a + n-1);
	int i;
	for(i=0;i<n;++i)
	{
		if(a[i] != i+1) break;
	}
	cout << i+1 << "\n";
}