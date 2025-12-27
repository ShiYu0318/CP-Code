#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

// 用 long long 會 TLE

signed main()
{
    ShiYu;
    int n,x,cnt; cin >> n;
    while(n--)
    {
        cin >> x; cnt = 0;
        for(int i=1; i*i <= x; i++)
        {
            if(x % i == 0) cnt += 1 + (x / i != i);
        }
        cout << cnt << '\n';
    }
}