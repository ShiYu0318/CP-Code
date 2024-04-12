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

// 習題 Q-2-5. 快速計算費式數列第 n 項
// 矩陣快速冪 struct 版

const int p = 1e9+7;

struct matrix
{
    int A[2][2] = {{0,0},{0,0}};
    matrix operator * (matrix &B)
    {
        matrix res;
        RPT(i,2) RPT(j,2) RPT(k,2) res.A[i][j] += A[i][k] * B.A[k][j];
        RPT(i,2) RPT(j,2) res.A[i][j] %= p;
        return res;
    }
} M = {1,1,1,0};

matrix fpow(int n)
{
    if(n == 0 || n == 1) return M;
    matrix t = fpow(n / 2), tt = t * t;
    return (n & 1 ? M * tt : tt);
}

signed main()
{
    ShiYu; int n;
    while(cin >> n && n != -1)
    {
        cout << fpow(n-1).A[0][0]; nl;
    }
}