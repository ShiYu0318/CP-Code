#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int a,b,c,d,i=1,ans=0,maxn=INT_MIN;
    while(cin >> a >> b >> c >> d)
    {
        int sum = a + b + c + d;
        if(sum > maxn)
        {
            ans = i;
            maxn = sum;
        }
        i++;
    }
    cout << ans << ' ' << maxn << "\n";
}