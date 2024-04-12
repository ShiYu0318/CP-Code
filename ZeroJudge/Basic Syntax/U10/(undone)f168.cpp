#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define rFOR(i,n) for(int i=n-1;i>=0;--i)
#define RPT(i,n) FOR(i,0,n)
#define input(x) for(auto &i : x) cin >> i
#define output(x) for(auto &i : x) cout << i << ' '
#define YN(x) cout << (x ? "YES" : "NO") << "\n";
#define all(x) x.rbegin(),x.rend()
#define int long long

// 貪心 WA 要遞迴枚舉

signed main()
{
    ShiYu
    int n; cin >> n;
    vector<int> v(n);
    int sum = 0;
    for(auto &i : v)
    {
        cin >> i;
        sum += i;
    }
    bool ans;
    if(sum % 3 != 0) ans = false;
    else 
    {
        int avg = sum / 3;
        sort(all(v));
        output(v); cout << "\n" <<  sum << ' ' << avg << "\n";
        int a=avg,b=avg,c=avg;
        RPT(i,v.size())
        {
            if(a >= v[i]) a -= v[i];
            else if(b >= v[i]) b -= v[i];
            else c -= v[i];
        }
        cout << a << ' ' << b << ' ' << c << "\n";
        YN(a == b && b == c && a == 0);
    }
}
