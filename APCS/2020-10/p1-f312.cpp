// 枚舉
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define FORn(i,n) for(int i=0;i<n;++i)
#define rFORn(i,n) for(int i=n-1;i>=0;--i)
#define int long long

signed main()
{
    int a1,b1,c1,a2,b2,c2,n;
    cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2 >> n;
    int j,maxn = INT_MIN,x,y;
    FORn(i,n+1)
    {
        j = n - i;
        x = a1 * i * i + b1 * i + c1;
        y = a2 * j * j + b2 * j + c2;
        maxn = max(maxn, x + y);
    }
    cout << maxn << '\n';
}