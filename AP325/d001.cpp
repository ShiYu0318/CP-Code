#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0),cin.tie(0);
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define rFOR(i,n) for(int i=n-1;i>=0;--i)
#define RPT(i,n) FOR(i,0,n)
#define input(x) for(auto &i : x) cin >> i
#define output(x) for(auto i : x) cout << i << " "
#define Yn(x) cout << (x ? "Yes" : "No") << "\n"
#define all(x) x.begin(),x.end()
#define int long long
#define pii pair<int,int>
#define F first
#define S second

// 遞迴

int eval()
{
    string x,y,t; int a,b; cin >> t;
    if(t == "f")
    {
        a = eval();
        return 2 * a - 1;
    }
    else if(t == "g")
    {
        a = eval();
        b = eval();
        return a + 2 * b - 3;
    }
    else return stol(t);
}

signed main()
{
    ShiYu
    cout << eval() << "\n";
}