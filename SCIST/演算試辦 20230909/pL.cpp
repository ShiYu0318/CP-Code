#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define FOR1(i,a) for(int i=1;i<=a;++i)


signed main()
{
	ShiYu;
    int n,q; cin >> n >> q;
    int a[n+1],s[n+1];
    FOR1(i,n) cin >> a[i];
    s[0] = 0;
    FOR1(i,n) s[i] = s[i - 1] + a[i];
    int l,r;
    while(q--)
    {
        cin >> l >> r;
        cout << s[r] - s[l -1] << "\n";
    }
	return 0;
}