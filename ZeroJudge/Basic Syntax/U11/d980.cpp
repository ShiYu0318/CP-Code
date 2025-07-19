#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define rFOR(i,n) for(int i=n-1;i>=0;--i)
#define RPT(i,n) FOR(i,0,n)
#define input(x) for(auto &i : x) cin >> i
#define output(x) for(auto i : x) cout << i << ' '
#define Yn(x) cout << (x ? "Yes" : "No") << '\n';
#define all(x) x.begin(),x.end()
#define int long long
#define F first
#define S second

signed main()
{
    ShiYu;
    int t; cin >> t;
    vector<int> v(3);
    FOR(i,1,t+1)
    {
        string ans;
        input(v);
        sort(all(v));
        if(v[0] <= 0 || !((v[0] + v[1] > v[2]) && abs(v[0] - v[1]) < v[2])) ans = "Invalid";
        else if(v[0] == v[1] && v[1] == v[2]) ans = "Equilateral";
        else if(v[0] == v[1] || v[1] == v[2]) ans = "Isosceles";
        else if(v[0] != v[1] && v[1] != v[2] && v[2] != v[0]) ans = "Scalene";
        cout << "Case " << i << ": " << ans << '\n';
    }     
}
