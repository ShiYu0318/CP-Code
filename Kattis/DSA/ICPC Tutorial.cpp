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
const double eps = 1e-8;


// complexity 快速冪 遞迴

// 階乘
int f(int n)
{
    if(n == 0) return 1;
    return n * f(n-1);
}

// 2^n
int g(int n)
{
    if(n == 1) return 2;
    return 2 * g(n-1);
}

int fpow(int a, int b)
{
    if(b == 1) return a;
    int temp = fpow(a, b/2);
    return (b % 2 ? a : 1) * temp * temp;
}

signed main()
{
    ShiYu;
    int m,n,t; cin >> m >> n >> t;
    long double sum;
    bool TLE = false;
    switch(t)
    {
        case 1:
        {
            if(n > 12) TLE = true;
            else n = f(n);
            break;
        }
        case 2:
        {
            if(n > 20) TLE = true;
            else n = g(n);
            break;
        }
        case 3:
        {
            n = fpow(n,4);
            break;
        }
        case 4:
        {
            n = fpow(n,3);
            break;
        }
        case 5:
        {
            n = n * n;
            break;
        }
        case 6:
        {
            sum = (long double)log2(n) * n;
            break;
        }
        case 7:
        {
            break;
        }
    }
    if((t == 1 || t == 2) && TLE) cout << "TLE\n";
    else if(t == 6) cout << (m - sum >= eps && sum > 0 ? "AC" : "TLE") << "\n";
    else cout << (n <= m && n > 0 ? "AC" : "TLE") << "\n";
}
