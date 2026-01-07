#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define F first
#define S second
#define EB emplace_back
#define endl '\n'
#define nl cout << '\n'
#define SZ(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define RPT(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define rFOR(i,n) for(int i=n-1; i>=0; --i)
#define input(x) for(auto &i:x) cin >> i
#define output(x) for(auto i:x) cout << i << ' '; nl
#define outputN(x,n) RPT(i,n) cout << x[i] << " \n"[i == n-1];
#define Yn(x) cout << (x ? "Yes" : "No") << '\n';

// Greedy

signed main()
{
    ShiYu;
    int n; cin >> n;
    vi v(n); input(v);
    int a = 0, b = 0, now = v[0];

    // 正負正
    if(v[0] <= 0)
    {
        now = 1;
        a += 1-v[0];
    }
    FOR(i,1,n)
    {
        now += v[i];
        if(i & 1) // 奇數 負的
        {
            if(now >= 0)
            {
                a += now+1;
                now = -1;
            }
        }
        else // 偶數 正的
        {
            if(now <= 0)
            {
                a += 1-now;
                now = 1;
            }
        }
    }

    // 負正負
    now = v[0];
    if(v[0] >= 0)
    {
        now = -1;
        b += v[0]+1;
    }
    FOR(i,1,n)
    {
        now += v[i];
        if(i & 1) // 奇數 正的
        {
            if(now <= 0)
            {
                b += 1-now;
                now = 1;
            }
        }
        else // 偶數 負的
        {
            if(now >= 0)
            {
                b += now+1;
                now = -1;
            }
        }
    }
    cout << min(a,b) << '\n';
}