#include <bits/stdc++.h>
using namespace std;

// 雙指針
// 偏思考 + 優化技巧

signed main()
{
    int n; cin >> n;
    vector<int> v(n);
    long long sum = 0, cnt = 0;
    for(auto &i:v)
    {
        cin >> i;
        sum += i;
    }
    sum *= n-1;
    sort(v.begin(), v.end());
    for(int l=0,r=n; l<n; ++l)
    {
        r = max(l+1, r);
        while(l < r-1 && v[l] + v[r-1] >= 1e8) r--;
        cnt += n - r;
    }
    cout << sum - cnt * 100000000 << "\n";
}