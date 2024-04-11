#include<bits/stdc++.h>
#define int long long
#define all(x) x.begin(), x.end()
#define RPT(i,n) for(int i=0;i<n;++i)
using namespace std;

// 例題 P-2-2. 離散化 – sort
// 離散化 struct 版

struct sparse
{
    vector<int> a;
    sparse(const vector<int> &v):a(v)
    {
        sort(all(a));
        a.erase(unique(all(a)),a.end());
    }
    int operator()(int x) const
    {
        return lower_bound(all(a), x) - a.begin();
    }
};

signed main()
{
    int n; cin >> n;
    vector<int> data(n);
    for(auto &i : data) cin >> i;
    sparse discrete(data);
    RPT(i,n) cout << discrete(data[i]) << " \n"[i == n-1];
}