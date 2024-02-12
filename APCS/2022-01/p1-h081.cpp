#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int n,d; cin >> n >> d;
    int a, buy = -1, sell , ans = 0;
    cin >> a; buy = a; n--;
    while(n--)
    {
        cin >> a;
        if(buy != -1 && a >= buy + d)
        {
            ans -= a - buy;
            sell = a;
            buy = -1;
        }
        if(buy == -1 && a <= sell - d) buy = a;
    }
    cout << ans << "\n";
}