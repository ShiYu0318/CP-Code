#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0)
#define ll long long
#define FOR(i,a,b) for(int i=a;i<b;++i)


signed main()
{
	ShiYu;
    int n; cin >> n;
    int a[n];
    FOR(i,0,n) cin >> a[i];
    sort(a,a+n);
    FOR(i,0,n) cout << a[i] << ' ';
	return 0;
}