#include<bits/stdc++.h>
#define int long long
#define all(x) x.begin(), x.end()
#define RPT(i,n) for(int i=0;i<n;++i)
using namespace std;
// 離散化
signed main()
{
    int n; cin >> n;
    int original[n], result[n]; vector<int> discrete(n);
    RPT(i,n)
    {
        cin >> original[i];
        discrete[i] = original[i];
    }
    sort(all(discrete));
    discrete.resize(unique(all(discrete)) - discrete.begin());
    RPT(i,n)
    {
        result[i] = lower_bound(all(discrete), original[i]) - discrete.begin();
    }
    RPT(i,n) cout << result[i] << " \n"[i == n-1];
}