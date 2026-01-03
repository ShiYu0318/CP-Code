#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()

// 偏思考 + 優化技巧

int main()
{
    int n; cin >> n;
    vector<int> v(n); for(auto &i:v) cin >> i;
    sort(all(v));
    int q; cin >> q;
    while(q--)
    {
        int l,r; cin >> l >> r;
        cout << upper_bound(all(v),r) - lower_bound(all(v),l) << "\n";
    }
}