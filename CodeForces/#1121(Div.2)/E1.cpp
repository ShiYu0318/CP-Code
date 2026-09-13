#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
// Type --------------------------------------------------------------------
#define int long long
#define ull unsigned long long
#define pii pair<int,int>
#define vi vector<int>
#define vii vector<pair<int,int>>
#define MM mx = INT_MIN, mi = INT_MAX
#define pq priority_queue
#define pq_min priority_queue<int,vector<int>,greater<int>>
// Simple ------------------------------------------------------------------
#define F first
#define S second
#define MP make_pair
#define EB emplace_back
// Function ----------------------------------------------------------------
#define SZ(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define sortall(x) sort(x.begin(), x.end())
#define remax(a,b) a = (a > b ? a : b)
#define remin(a,b) a = (a < b ? a : b)
// Loop --------------------------------------------------------------------
#define RPT(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define rFOR(i,n) for(int i=n-1; i>=0; --i)
#define rFOR1(i,n) for(int i=n; i>=1; --i)
// I/O ----------------------------------------------------------------------
#define nl cout << '\n'
#define coutN(x) cout << x << '\n'
#define dbg(x) cerr << #x << " = " << x << '\n';
#define input(x) for(auto &i:x) cin >> i
// const -------------------------------------------------------------------
const int MOD = 998244353;

// ==========================================================================================
//  E1. A Prime Flood
//  f(b) 只跟 (min,max) 有關；F(u,w) 貪心 -> 以 w 為階段的一維 DP，配二維容斥計數
// ==========================================================================================

void solve()
{
    int n; cin >> n;
    vi a(n), cnt(n+2, 0); input(a);
    for(int x:a) cnt[x]++;

    // rad[w] = w 的相異質因數乘積
    vi rad(n+1, 1);
    vector<char> comp(n+1, 0);
    FOR(p,2,n+1)
    {
        if(!comp[p])
        {
            for(int w = p; w <= n; w += p) 
            { 
                comp[w] = 1; 
                rad[w] *= p; 
            }
        }
    }

    vi pre(n+2, 0), pw(n+1);
    FOR(v,1,n+1) pre[v] = pre[v-1] + cnt[v];
    pw[0] = 1;
    FOR(i,1,n+1) pw[i] = pw[i-1] * 2 % MOD;
    auto P = [&](int l, int r) { return l > r ? 0LL : pre[r] - pre[l-1]; };

    vi dp(n+2, 0); // dp[u] = F(u, 當前的 M)
    int ans = 0;
    FOR(M,1,n+1)
    {
        rFOR1(u, M-1) if(u % rad[M] == 0) dp[u] = dp[u-1];
        dp[M] = M;
        FOR(m,1,M+1)
        {
            int N = pw[P(m,M)] - pw[P(m+1,M)] - pw[P(m,M-1)] + pw[P(m+1,M-1)];
            N = (N % MOD + MOD) % MOD;
            if (N) ans = (ans + dp[m] * N) % MOD;
        }
    }
    coutN(ans);
}

signed main()
{
    ShiYu;
    int t = 1;
    cin >> t; // hide it when one case
    while(t--) solve();
}