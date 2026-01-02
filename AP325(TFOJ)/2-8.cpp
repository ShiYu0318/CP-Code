#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define F first
#define S second
#define EB emplace_back
#define endl "\n"
#define SZ(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define RPT(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define rFOR(i,n) for(int i=n-1; i>=0; --i)
#define input(x) for(auto &i:x) cin >> i
#define output(x) for(auto i:x) cout << i << ' '; cout << endl;

// 習題 Q-2-8. 模逆元 (*)
// 模逆元 快速冪

/*
(a * b) % p = 1
a 模 p 反元素：b

費馬小定理：
若 P 為質數, 對任意正整數 a,
(a^(P-2) % P) 是 a 在 [1, P-1] 區間的唯一乘法反元素
*/

int p;

int fpow(int a, int b)
{
    if(b == 1) return a;
    int t = fpow(a, b / 2) % p;
    return (b & 1 ? a : 1) * t % p * t % p;
}

signed main()
{
    int n; cin >> n >> p;
    RPT(i,n)
    {
        int a; cin >> a;
        cout << fpow(a,p-2) % p << " \n"[i == n-1];
    }
}