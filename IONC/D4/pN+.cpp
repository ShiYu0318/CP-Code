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

int n, ans;

void elf(int tb[10][10], int ck[10], int x, int y)
{
    if(x > n) { ans++; return; }
    if(x == -1 && y == -1) {x++;y++;}
    else tb[x-1][y] = 1; ck[y] = 1;
    RPT(i,n) {{RPT(j,n) cout << tb[i][j];} cout <<'\n';}
    cout << "ck:"; outputN(ck,n);
    cout << '\n';
    RPT(i,n)
    {
        // cout << x << ' ' << y << endl;
        if(ck[i]) continue;
        elf(tb, ck, x+1, i);
        // tb[x][y] = 0; ck[y] = 0;
    }
    return;
}

signed main()
{
    ShiYu;
    cin >> n;
    int tb[10][10] = {0}, ck[10] = {0};
    elf(tb,ck,-1,-1);
    cout << ans * ans ; nl;
}