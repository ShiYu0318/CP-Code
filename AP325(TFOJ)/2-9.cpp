#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define F first
#define S second
#define EB emplace_back
#define SZ(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define RPT(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define rFOR(i,n) for(int i=n-1; i>=0; --i)
#define input(x) for(auto &i:x) cin >> i
#define output(x) for(auto i:x) cout << i << ' '; cout << endl;

// 例題 P-2-9. 子集合乘積(折半枚舉) (@@)
// 遞迴枚舉子集合 費馬小定理 模逆元 快速冪 折半枚舉

int p;

void gen(const vi &v, map<int,int> &m, int t, int res)
{
    if(t == SZ(v)) { m[res%p]++; return; }
    gen(v,m,t+1,res * v[t] % p); gen(v,m,t+1,res);
}

int fpow(int a, int b)
{
    if(b == 1) return a;
    int t = fpow(a, b/2) % p;
    return (b & 1 ? a : 1) * t % p * t % p;
}

signed main()
{
    ShiYu;
    int n; cin >> n >> p;
    int la = n/2, lb = n - la;
    vi a(la), b(lb);
    input(a); input(b);

    map<int,int> ma,mb;
    gen(a,ma,0,1); gen(b,mb,0,1);
    ma[1]--; mb[1]--;

    int ans = ma[1] + mb[1];
    for(auto i:ma)
    {
        int iv = fpow(i.F,p-2) % p;
        ans = (ans + i.S * mb[iv]) % p;
    }
    cout << ans << '\n';
}