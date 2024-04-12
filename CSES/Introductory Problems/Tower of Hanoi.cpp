#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0),cin.tie(0);
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define rFOR(i,n) for(int i=n-1;i>=0;--i)
#define RPT(i,n) FOR(i,0,n)
#define input(x) for(auto &i : x) cin >> i
#define output(x) for(auto i : x) cout << i << ' '
#define Yn(x) cout << (x ? "Yes" : "No") << "\n"
#define all(x) x.begin(),x.end()
#define int long long
#define pii pair<int,int>
#define F first
#define S second

// 遞迴 河內塔

int fpow(int n)
{
    if(n == 1) return 2;
    int t = fpow(n/2);
    return (n % 2 ? 2 : 1) * t * t;
}

void f(int n, int fst, int end, int tmp)
{
    if(!n) return;
    f(n-1, fst, tmp, end);
    cout << fst << ' ' << end << "\n";
    f(n-1, tmp, end, fst);
}

signed main()
{
    ShiYu;
    int n; cin >> n;
    cout << fpow(n) - 1 << "\n";
    f(n,1,3,2);
}
