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

const int N = 105;
int tb[N][N];

signed main()
{
    ShiYu; int n;
    while(cin >> n && n)
    {
        RPT(i,n) RPT(j,n) cin >> tb[i][j];
        vector<int> r(n,0), c(n,0);
        RPT(i,n) RPT(j,n) {r[i] += tb[i][j]; c[j] += tb[i][j];}
        bool ans = true;
        RPT(i,n) if(r[i] & 1 || c[i] & 1) {ans = false; break;}
        int a=0,b=0,x,y;
        if(ans) cout << "OK\n";
        else
        {
            RPT(i,n)
            {
                if(r[i] & 1) {++a; x = i;}
                if(c[i] & 1) {++b; y = i;}
            }
            if(a == 1 && b == 1) cout << "Change bit (" << x+1 << "," << y+1 << ")\n";
            else cout << "Corrupt\n";
        }
    }
}