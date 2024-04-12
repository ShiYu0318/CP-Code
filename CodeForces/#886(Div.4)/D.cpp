#include <bits/stdc++.h>
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

signed main()
{
    int t; cin >> t;
    while(t--)
    {
        int n,k; cin >> n >> k;
        int a[n],tmp=0,ans=0;
        for(int i=0;i<n;++i) cin >> a[i];
        sort(a,a+n);
        for(int i=0;i<n-1;++i)
        {
            if(a[i+1] - a[i] <= k)
            {
                tmp++;
                if(tmp > ans) ans = tmp;
            }
            else tmp = 0;
        }
        cout << n - ans - 1 << "\n";
    }
}