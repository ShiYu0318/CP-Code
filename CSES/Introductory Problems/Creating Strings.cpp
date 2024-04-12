#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ShiYu; ios_base::sync_with_stdio(0); cin.tie(0)
#define eb emplace_back
#define all(x) x.begin(),x.end()

// 全排列

signed main()
{
    ShiYu;
    string s; cin >> s;
    sort(all(s));
    vector<string> ans;
    ans.eb(s);
    while(next_permutation(all(s))) ans.eb(s);
    cout << ans.size() << "\n";
    for(auto i : ans) cout << i << "\n";
}