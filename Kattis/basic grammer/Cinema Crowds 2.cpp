#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int n,m; cin >> n >> m;
    int t,sum=0;
    while(m--)
    {
        cin >> t;
        if(sum + t > n) break;
        sum += t;
    }
    cout << m+1 << "\n";
}