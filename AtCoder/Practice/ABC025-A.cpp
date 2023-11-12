#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i,n) for(int i=1;i<n;++i)

int digit(int n)
{
    int t = 0;
    while(n != 0)
    {
        t += n % 10;
        n /= 10;
    }
    return t;
}

signed main()
{
    int n; cin >> n;
    int ans = INT_MAX;
    FOR(i,n)
    {
        int sum = 0, a = i, b = n - a;
        sum += digit(a); sum += digit(b);
        ans = min(sum,ans);
    }
    cout << ans << "\n";
}