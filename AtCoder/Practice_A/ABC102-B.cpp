#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;++i)
#define all(x) x.begin(),x.end()

signed main()
{
    int n; cin >> n;
    int t;
    vector<int> v;
    while(n--)
    {
        cin >> t;
        v.push_back(t);
    }
    sort(all(v));
    cout << v[v.size()-1] - v[0] << "\n";
}