#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define rFOR(i,n) for(int i=n-1;i>=0;--i)
#define RPT(i,n) FOR(i,0,n)
#define input(x) for(auto &i : x) cin >> i
#define output(x) for(auto &i : x) cout << i << ' '
#define inputD(x,a,b) RPT(i,a) RPT(j,b) cin >> x[i][j]
#define dbg(x) cout << #x << "=" << x << ' ';
#define Yn(x) cout << (x ? "Yes" : "No") << '\n';
#define all(x) x.begin(),x.end()
#define int long long

signed main()
{
    ShiYu;
    string s; cin >> s;
    RPT(i,6)
    {
        cout << abs(s[i+1] - s[i]);
    }
    cout << '\n';
}
