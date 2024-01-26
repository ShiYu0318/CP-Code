#include<bits/stdc++.h>
using namespace std;

signed main()
{
    int n; cin >> n;
    vector<int> v(n);
    for(auto &i : v) cin >> i;
    for(int i = 0; i < n; i += 2) cout << v[i] << " ";
    cout << "\n";
    for(int i = 1; i < n; i += 2) cout << v[i] << " ";
    cout << "\n";
}