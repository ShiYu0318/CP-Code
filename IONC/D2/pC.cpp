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

// AC
// Daniel == LJH ?

const int N = 3005;
int dp[N][N]; vi v;

int TD(int i, int j)
{
    if(i > j) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    int a = v[i] + min(TD(i+1,j-1), TD(i+2,j)),
        b = v[j] + min(TD(i+1,j-1), TD(i,j-2));
    return dp[i][j] = max(a,b);
}

signed main()
{
    ShiYu;
    int n; cin >> n;
    v.resize(n); input(v);
    memset(dp,-1,sizeof(dp));
    int x = TD(0,n-1), sum = 0;
    for(auto i:v) sum += i;
    cout << x - (sum - x) << endl;

    // greedy 爛掉
    // int l = 0, r = n-1, x = 0, y = 0, t = 1;
    // while(l <= r)
    // {
    //     if(t)
    //     {
    //         if(x + v[l] - y > x + v[r] - y) {x += v[l]; ++l;}
    //         else {x += v[r]; --r;}
    //         t = 1 - t;
    //     }
    //     else
    //     {
    //         if(x - (y + v[l]) < x - (y + v[r])) {y += v[l]; ++l;}
    //         else {y += v[r]; --r;}
    //         t = 1 - t;
    //     }
    //     FOR(i,l,r+1) cout << v[i] << " \n"[i==r];
    //     cout << "x:" << x << " y:" << y << endl;
    // }
    // cout << x - y << endl;
}