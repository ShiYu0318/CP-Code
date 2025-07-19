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

// 習題 Q-1-2. 合成函數(2) (APCS201902) 
// 遞迴 同 P-1-1

int eval()
{
    string t; cin >> t;
    int x, y, z;
    if(t == "f")
    {
        x = eval();
        return 2 * x - 3;
    }
    else if(t == "g")
    {
        x = eval();
        y = eval();
        return 2 * x + y - 7;
    }
    else if(t == "h")
    {
        x = eval();
        y = eval();
        z = eval();
        return 3 * x - 2 * y + z;
    }
    else return stol(t);
}

signed main()
{
    ShiYu;
    cout << eval(); nl;
}