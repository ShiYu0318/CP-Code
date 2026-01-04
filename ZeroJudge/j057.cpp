#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ShiYu ios_base::sync_with_stdio(0),cin.tie(0)

// CPE 11634

signed main()
{
    ShiYu;
    int n;
    while(cin >> n && n)
    {
        int ans = 0, A[10000] = {0};
        while (!A[n])
        {
            A[n] = 1;
            n *= n;
            n /= 100;
            n %= 10000;
            ++ans;
        }
        cout << ans << '\n';
    }
}