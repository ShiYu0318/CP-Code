#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FOR(i,n) for(int i=sqrt(n);i>0;--i)
#define int long long

signed main()
{
    ShiYu;
    int n; cin >> n;
    int a,q,minn=INT_MAX;
    FOR(i,n)
    {
        if(n % i == 0)
        {
            a = n / i; q = 0;
            while(a != 0)
            {
                a /= 10;
                q++;
            }
            minn = min(minn,q);
        }
    }
    cout << minn << '\n';
}