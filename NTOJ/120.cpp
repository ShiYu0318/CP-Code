#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0)
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define rFOR(i,n) for(int i=n-1;i>=0;--i)
#define RPT(i,n) FOR(i,0,n)
#define input(x) for(auto &i : x) cin >> i
#define output(x) for(auto i : x) cout << i << ' '
#define Yn(x) cout << (x ? "Yes" : "No") << "\n"
#define all(x) x.begin(),x.end()
#define int long long
#define pii pair<int,int>
#define F first
#define S second

// 前綴和裸題

signed main()
{
    ShiYu;
    int n; cin >> n;
    vector<int> v(n+1); v[0] = 0;
    RPT(i,n)
    {
        cin >> v[i+1];
        v[i+1] += v[i];
    }
    int q; cin >> q;
    int l,r;
    while(q--)
    {
        cin >> l >> r;
        if(l > r) swap(l,r);
        cout << v[r] - v[l-1] << "\n";
    }
}
