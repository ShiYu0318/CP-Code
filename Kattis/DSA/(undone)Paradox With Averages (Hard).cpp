#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0),cin.tie(0);
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

// 

signed main()
{
    ShiYu
    int t,a,b; cin >> t >> a >> b;
    vector<int> x(a), y(b);
    int suma = 0, sumb = 0;
    for(auto &i:x)
    {
        cin >> i;
        suma += i;
    }
    for(auto &i:y)
    {
        cin >> i;
        sumb += i;
    }

    double avga = suma / a, avgb = sumb / b;
    int ans = 0;
    for(auto i:x)
    {
        if((double)(suma - i) / (a - 1) > avga && (double)(sumb + i) / (b + 1) > avgb)
        {
            ++ans;
        }
    }
    cout << ans << "\n";
}
