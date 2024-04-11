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
#define vi vector<int>

// 

const int p = 1e9+7;
vi mt = {1,1,1,0};

vi matrix_multi(vi a, vi b)
{
    return {
        (a[0]*b[0] + a[1]*b[2]) % p,
        (a[0]*b[1] + a[1]*b[3]) % p,
        (a[2]*b[0] + a[3]*b[2]) % p,
        (a[2]*b[1] + a[3]*b[3]) % p
    };
}

vi fpow(int n)
{
    if(n == 0 || n == 1) return mt;
    vi t = fpow(n/2), tt = matrix_multi(t,t);
    return (n & 1 ? matrix_multi(mt, tt) : tt);
}

signed main()
{
    ShiYu
    int n;
    while(cin >> n && n != -1)
    {
        vi m = fpow(n-1);
        cout << m[0] << '\n';
    }
}
