#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define rFOR(i,n) for(int i=n-1;i>=0;--i)
#define RPT(i,n) FOR(i,0,n)
#define input(x) for(auto &i : x) cin >> i
#define output(x) for(auto &i : x) cout << i << ' '
#define Yn(x) cout << (x ? "Yes" : "No") << '\n';
#define all(x) x.begin(),x.end()
#define int long long

int f91(int n)
{
    if(n <= 100) return f91(f91(n+11));
    else return n-10;
}

signed main()
{
    ShiYu;
    int n;
    while(cin >> n && n)
    {
        cout << "f91(" << n << ") = " << f91(n) << '\n';
    }
}
