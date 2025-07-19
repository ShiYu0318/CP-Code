#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define input(x) for(auto &i : x) cin >> i
#define output(x) for(auto &i : x) cout << x << ' '

signed main()
{
	ShiYu;
    int a[5] = {4,8,7,6,3};
    int n; cin >> n;
    cout << a[n % 5] << ' ';
    a[n % 5] += n;
    cout << a[a[n % 5] % 5] << ' ';
    a[a[n % 5] % 5] += n;
    int ans = a[0];
    FOR(i,1,5) ans *= a[i];
    cout << ans << '\n';
	return 0;
}

