#include <bits/stdc++.h>
using namespace std;
#define ll long long

// 波浪排列 奇偶性

int main()
{
    int n,t; cin >> n;
    vector<int> v(n),ans(n); for(auto &i:v) cin >> i;
    sort(v.begin(), v.end());
    for(int i=0,j=0; i < n; ++i)
    {
        ans[i] = v[j];
        // cout << i << ' ' << j << '\n';
        if(i % 2) j = n - j;
        else j = n - j - 1;

    }
    for(int i=n-1; i>=0; --i) cout << ans[i] << ' ';
}