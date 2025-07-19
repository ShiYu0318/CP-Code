#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long

signed main()
{
    ShiYu;
    int n,ans;
    while(cin >> n && n)
    {
        ans = 0;
        while(n%2)
        {
            n /= 2;
            ++ans;
        }
        cout << ans << '\n';
    }
}
