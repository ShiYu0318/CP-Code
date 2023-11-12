#include <bits/stdc++.h>
#define ShiYu ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
#define int long long
#define FOR(i,n) for(int i=0;i<n;++i)

int l[100000];

signed main()
{
    ShiYu
    int t; cin >> t;
    FOR(i,t)
    {
        int h=0,l=0;
        int n; cin >> n;
        int a; cin >> a; int b=a;
        n--;
        while(n--)
        {
            cin >> a;
            if(a > b) h++;
            else if(a < b) l++;
            b = a;
        }
        cout << "Case " << i+1 << ": " << h << " " << l << "\n";
    }
    
}