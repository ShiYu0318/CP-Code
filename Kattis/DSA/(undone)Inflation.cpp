#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0),cin.tie(0);
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define rFOR(i,n) for(int i=n-1;i>=0;--i)
#define RPT(i,n) FOR(i,0,n)
#define input(x) for(auto &i : x) cin >> i
#define output(x) for(auto i : x) cout << i << ' '
#define Yn(x) cout << (x ? "Yes" : "No") << "\n";
#define all(x) x.begin(),x.end()
#define int long long
#define pii pair<int,int>
#define F first
#define S second

// greedy

signed main()
{
    ShiYu
    int n; cin >> n;
    vector<int> v(n); input(v);
    sort(all(v));
    double ans = INT_MAX;
    RPT(i,n)
    {
        if(v[i] == 0)
        {
            ans = 0;
            break;
        }
        else if(v[i] == i+1) continue;
        else if(v[i] > i+1)
        {
            ans = -1;
            break;
        }
        else ans = min(ans,(double)(v[i])/(i+1));
    }
    if(ans == -1) cout << "impossible\n";
    else cout << ans << "\n";
}
