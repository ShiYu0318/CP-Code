#include<bits/stdc++.h>
using namespace std;

signed main()
{
    int n; cin >> n;
    vector<int> v(n);
    for(auto &i : v) cin >> i;
    for(int i=n-1;i>=0;--i) cout << v[i] << " ";
    cout << "\n";
}