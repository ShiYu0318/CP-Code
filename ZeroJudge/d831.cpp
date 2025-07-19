#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define F first
#define S second
#define EB emplace_back
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

// DSU 集合最大數量

vector<int> sum(1e6+5);

int Find(int x)
{
    return (sum[x] < 0 ? x : sum[x] = Find(sum[x]));
}

signed main()
{
    ShiYu;
    int n,m,x,y;
    while(cin >> n >> m)
    {
        fill(all(sum),-1);
        int mx = 1;
        while(m--)
        {
            cin >> x >> y;
            int a = Find(x);
            int b = Find(y);
            
            if(a != b)
            {
                sum[a] += sum[b];
                mx = max(mx, -sum[a]);
                sum[b] = a;
            }
        }
        cout << mx << '\n';
    }
}