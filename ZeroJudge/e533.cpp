#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define FOR(i,n) for(int i=0;i<n;++i)

int l[100000];

signed main()
{
    ShiYu;
    int t; cin >> t;
    int n[10];
    cout << "Lumberjacks:\n";
    while(t--)
    {
        FOR(i,10) cin >> n[i];
        bool type,ans=true;
        if(n[0] < n[1]) type = true;
        else type = false;
        FOR(i,9)
        {
            if((type && n[i] > n[i+1]) || (!type && n[i] < n[i+1]))
            {
                ans = false;
                break;
            }
        }
        cout << (ans ? "Ordered" : "Unordered") << '\n';
    }
}