#include<bits/stdc++.h>
using namespace std;

signed main()
{
    int n,m; cin >> n >> m;
    vector<vector<int>> v(n);
    vector<int> t(m);
    for(auto &i : v)
    {
        for(auto &j : t) cin >> j;
        i = t;
    }
    int k; cin >> k;
    for(auto &i : v) 
    {
        for(auto &j : i) cout << j * k << " ";
        cout << "\n";
    }
}