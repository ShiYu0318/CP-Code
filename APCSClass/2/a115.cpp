#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define F first
#define S second
#define EB emplace_back
#define MP make_pair
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

// 賓果遊戲 實作題

int tb[5][5], S[26];

bool cmp(pii a, pii b)
{
    return (a.F == b.F ? a.S < b.S : a.F > b.F);
}

signed main()
{
    ShiYu;
    vector< pair<int,int> > pos(26), ans;
    RPT(i,5) RPT(j,5) 
    {
        cin >> tb[i][j];
        pos[tb[i][j]] = {i,j};
    }
    int n, r[5] = {0}, c[5] = {0}, a=0, b=0;
    while(cin >> n && n != -1)
    {
        int i = pos[n].F, j = pos[n].S;
        S[n] = -1;
        ++r[i]; ++c[j];
        if(i == j) ++a;
        if(i+j == 4) ++b;
    }
    int maxn = 0;
    RPT(k,25)
    {
        int i = pos[k+1].F, j = pos[k+1].S;
        if(S[k+1] != -1)
        {
            S[k+1] += (r[i] == 4) + (c[j] == 4) + (i == j && a == 4) + (i + j == 4 && b == 4);
        }
        maxn = max(maxn, S[k+1]);
    }
    RPT(k,25) if(S[k+1] == maxn) {cout << k+1 << '\n'; break;}
}