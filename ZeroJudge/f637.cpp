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

string s;
int idx;

int f(int a)
{
    ++idx;
    if(s[idx] == '2') return f(a/4) + f(a/4) + f(a/4) + f(a/4);
    else if(s[idx] == '1') return a;
    else return 0;
}

signed main()
{
    ShiYu
    int n; cin >> s >> n;
    idx = -1;
    cout << f(n*n) << "\n";
}
