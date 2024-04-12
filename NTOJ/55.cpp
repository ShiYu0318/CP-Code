#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define FORn(i,n) for(int i=0;i<n;++i)
#define rFOR(i,n) for(int i=n-1;i>=0;--i)
#define input(x) for(auto &i : x) cin >> i
#define output(x) for(auto &i : x) cout << i << ' '
#define inputD(x,a,b) FORn(i,a) FORn(j,b) cin >> x[i][j]
#define dbg(x) cout << #x << "=" << x << ' ';
#define Yn(x) cout << (x ? "Yes" : "No") << "\n";
#define all(x) x.begin(), x.end()
#define int long long
#pragma GCC diagnostic ignored "-Wc++11-extensions"


signed main(void)
{
    int n; cin >> n;
    vector<int> v(n);
    input(v);
    sort(all(v));
    int q; cin >> q;
    int t;
    while(q--)
    {
        cin >> t;
        cout << upper_bound(all(v),t) - lower_bound(all(v),t) << "\n";
    }
}
