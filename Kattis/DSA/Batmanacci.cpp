#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
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

// 遞迴

const int SIZE = 1e5+5, MAXN = 1e18;
int L[SIZE];

char f(int n, int k)
{
    if(n == 1) return 'N';
    if(n == 2) return 'A';
    if(k <= L[n-2]) return f(n-2,k);
    return f(n-1,k - L[n-2]);
}

signed main()
{
    ShiYu;
    int n,k; cin >> n >> k;
    L[1] = 1;
    L[2] = 1;
    FOR(i,3,n) L[i] = min(MAXN, L[i-1] + L[i-2]);
    cout << f(n,k) << "\n";
}