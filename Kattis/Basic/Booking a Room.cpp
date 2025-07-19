#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define rFOR(i,a,b) for(int i=a;i>b;--i)
#define input(x,n) FOR(i,0,n) cin >> x[i];
#define dbg(x) cout << #x << "=" << x << ' ';
#define int long long
#define nl cout << '\n';

signed main()
{
    int r,n; cin >> r >> n;
    bool b[100];
    FOR(i,0,n) b[i] = false;
    int t;
    FOR(i,0,n)
    {
        cin >> t;
        b[t-1] = true;
    }
    // FOR(i,0,n) cout << i << ' ' << b[i] << '\n';
    bool ans = true;
    int i;
    for(i = 0; i < r; ++i)
    {
        if(b[i] == false)
        {
            ans = false;
            break;
        } 
    }
    if(ans) cout << "too late\n";
    else cout << i+1 << '\n';
}