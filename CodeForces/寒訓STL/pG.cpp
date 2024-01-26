#include<bits/stdc++.h>
using namespace std;

signed main()
{
    int n; cin >> n;
    vector<pair<int,int>> v(n);
    for(auto &i : v) cin >> i.first >> i.second;
    sort(v.begin(),v.end());
    for(auto &i : v) cout << i.first << " " << i.second << "\n";
}