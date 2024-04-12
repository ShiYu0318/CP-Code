#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0)

signed main()
{
    ShiYu;
    int t; cin >> t;
    set<int> s;
    int n;
    while(t--)
    {
        cin >> n;
        s.insert(n);
    }
    cout << s.size() << "\n";
}