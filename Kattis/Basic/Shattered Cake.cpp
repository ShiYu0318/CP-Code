#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;++i)

signed main()
{
    int n,t; cin >> n >> t;
    int w,l,sum=0;
    while(t--)
    {
        cin >> w >> l;
        sum += w * l;
    }
    cout << sum / n << '\n';
}