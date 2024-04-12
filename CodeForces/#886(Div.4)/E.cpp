#include <bits/stdc++.h>
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
using namespace std;
// not finish
signed main()
{
    ShiYu;
    int t; cin >> t;
    while(t--)
    {
        int n,c; cin >> n >> c;
        int a[n],sum=0,l=0;
        
        for(int i=0;i<n;++i) cin >> a[i];
        while(1)
        {
            bool ans=0,over=0;
            sum = 0;
            l++;
            for(int i=0;i<n;++i)
            {
                sum += pow(a[i] + l * 2,2);
                if(sum > c)
                {
                    over = 1;
                    break;
                }
            }
            cout << '\n';
            if(over) break;
            if(sum == c)
            {
                ans = 1;
                break;
            }
        }
        cout << l << "\n";
    }
}