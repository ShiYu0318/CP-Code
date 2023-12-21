#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i,a,b) for(int i=a;i<b;++i)

int a[200005];

signed main()
{
    int n; cin >> n;
    int ans = 0;
    FOR(i,0,n) cin >> a[i];
    FOR(i,1,n)
    {
        if(a[i] < a[i-1])
        {
            ans += a[i-1] - a[i];
            a[i] += a[i-1] - a[i];
        }
    }
    cout << ans << "\n";
}