#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(int i=0;i<=n;++i)
#define int long long

signed main(void)
{
    int n,a,b; cin >> n >> a >> b;
    int ans=0;
    FOR(i,n)
    {
        int t = i,sum = 0;
        while(t != 0)
        {
            sum += t % 10;
            t /= 10;
        }
        if(a <= sum && sum <= b) ans += i;
    }
    cout << ans << '\n';
}