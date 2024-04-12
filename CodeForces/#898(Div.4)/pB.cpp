#include <bits/stdc++.h>
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FOR(i,n) for(int i=0;i<n;++i)
#define input(x) for(auto &i : x) cin >> i
#define output(x) for(auto &i : x) coutS(i)
#define YN(x) cout << (x ? "YES" : "NO") << "\n"
#define nl cout << '\n'
using namespace std;

void solve()
{	
	int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        int a[n];
        FOR(i,n) cin >> a[i];
        sort(a,a+n);
        a[0] += 1;
        int sum = a[0];
        for(int i=1;i<n;++i) sum *= a[i];
        cout << sum << "\n";
    }
}

signed main()
{
	ShiYu;
	solve();
	return 0;
}