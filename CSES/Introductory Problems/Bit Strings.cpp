#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define ShiYu ios_base::sync_with_stdio(0);cin.tie(0)

int MOD = 1e9+7;

signed main()
{
    ShiYu;
    int n; cin >> n;
    int ans = 1;
    while(n--)
    {
        ans <<= 1;
        ans %= MOD;
    }
    cout << ans << "\n";
}