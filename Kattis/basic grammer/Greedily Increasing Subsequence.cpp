#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;++i)

signed main()
{
    int t; cin >> t;
    vector<int> v;
    int n,maxn=INT_MIN;
    while(t--)
    {
        cin >> n;
        if(n > maxn)
        {
            v.push_back(n);
            maxn = n;
        }
    }
    cout << v.size() << "\n";
    FOR(i,v.size()) cout << v[i] << " ";
    return 0;
}