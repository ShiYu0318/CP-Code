#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ShiYu ios_base::sync_with_stdio(0);cin.tie(0)

// 數學思考

signed main()
{
    ShiYu;
    int n; cin >> n;
    int ans = 0;
    while(n)
    {
        ans += n / 5;
        n /= 5;
    }
    cout << ans << "\n";
}