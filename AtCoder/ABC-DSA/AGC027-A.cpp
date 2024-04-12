#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0)
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define rFOR(i,n) for(int i=n-1;i>=0;--i)
#define RPT(i,n) FOR(i,0,n)
#define input(x) for(auto &i : x) cin >> i
#define output(x) for(auto i : x) cout << i << ' '
#define Yn(x) cout << (x ? "Yes" : "No") << "\n";
#define all(x) x.begin(),x.end()
#define int long long
#define F first
#define S second

// greedy

signed main()
{
    ShiYu;
    int n,x; cin >> n >> x;
    vector<int> v(n); input(v);
    sort(all(v));
    int ans = 0,sum = 0;
    for(auto i:v)
    {
        if((ans + 1 == n) && (x - sum != i)) break;
        if(sum + i <= x) 
        {
            sum += i;
            ++ans;
        }
        else break;
    }
    cout << ans << "\n";
}
