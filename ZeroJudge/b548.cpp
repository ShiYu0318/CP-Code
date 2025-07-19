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

int tb[5][5], vis[5][5];

bool cmp(pii a, pii b)
{
    if(a.F == b.F) return a.S < b.S;
    return a.F > b.F;
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
    // RPT(i,5) RPT(j,5) cout << tb[i][j] << " \n"[j==4];cout << endl;
    int n;
    while(cin >> n && n != -1) vis[pos[n].F][pos[n].S] = true;
    // RPT(i,5) RPT(j,5) cout << vis[i][j] << " \n"[j==4];cout << endl;
    int r[5] = {0}, c[5] = {0}, a=0, b=0;
    RPT(i,5) RPT(j,5)
    {
        r[i] += vis[i][j];
        c[i] += vis[j][i];
        if(i == j) a += vis[i][j];
        if(i+j == 4) b += vis[i][j];
    }
    // cout << a << ' ' << b << '\n';output(r);output(c);cout << endl;

    RPT(i,5) RPT(j,5)
    {
        int p = 0;
        if(!vis[i][j])
        {
            if(r[i] + 1 == 5) ++p;
            if(c[j] + 1 == 5) ++p;
            if(i == j && a + 1 == 5) ++p;
            if(i + j == 4 && b + 1 == 5) ++p;
        }
        if(p) ans.EB(make_pair(p, tb[i][j]));
    }
    sort(all(ans), cmp);
    // for(auto i:ans) cout << i.F << ' ' << i.S << '\n';
    cout << ans[0].S << endl;
}