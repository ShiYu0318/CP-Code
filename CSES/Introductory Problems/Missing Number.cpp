#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0);cin.tie(0)
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define input(x,n) FOR(i,0,n) cin >> x[i];
#define int long long

int a[200005];

signed main()
{
	ShiYu;
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