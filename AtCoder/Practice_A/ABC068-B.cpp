#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int n; cin >> n;
    int i=-1,sum=0,ans;
    while(sum <= n)
    {
        ans = sum;
        i++;
        sum = pow(2,i);
    }
    cout << ans << "\n";
}