#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define FOR(i,a,b) for(int i=a;i<b;++i)

signed main(void) {
    ShiYu
    int n, k, a, b; cin >> n >> k >> a >> b;
    int x = 0, y = 0, min = INT_MAX, d;
    FOR(i,0,11)
    {
        FOR(j,0,11)
        {
            d = n - i * a - j * b - k;
            if (d < 0) continue;
            if (d <= min)
            {
                min = d;
                x = i; y = j;
            }
        }
    }
    cout << x << ' ' << y << ' ' << min << "\n";
}