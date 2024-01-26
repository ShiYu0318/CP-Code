#include<bits/stdc++.h>
using namespace std;

signed main()
{
    int n; cin >> n;
    vector<string> v(n);
    for(auto &i : v) cin >> i;
    sort(v.begin(),v.end());
    for(auto &i : v) cout << i << " ";    
    cout << "\n";
}