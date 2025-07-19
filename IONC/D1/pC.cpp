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

bool cmp(pii a, pii b)
{
    if(a.F == b.F) return a.S < b.S;
    return a.F > b.F;
}

signed main()
{
    ShiYu;
    int n,x; cin >> n >> x;
    vector<pii> v(n);
    RPT(i,n)
    {
        cin >> v[i].F;
        v[i].S = i+1;
    }
    sort(all(v),cmp);
    RPT(i,n-3)
    {
        if(v[i].F > x) continue;
        FOR(j,i+1,n-2)
        {
            if(v[i].F + v[j].F > x) continue;
            FOR(k,j+1,n-1)
            {
                if(v[i].F + v[j].F + v[k].F > x) continue;
                FOR(l,k+1,n)
                {
                    if(v[i].F + v[j].F + v[k].F + v[l].F < x) break;
                    if(v[i].F + v[j].F + v[k].F + v[l].F == x) 
                    {
                        cout << v[i].S << ' ' << v[j].S << ' ' << v[k].S << ' ' << v[l].S << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << "-1\n";
}