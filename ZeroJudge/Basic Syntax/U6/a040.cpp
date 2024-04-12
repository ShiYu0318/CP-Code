// 窮舉
#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0)
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define rFOR(i,n) for(int i=n-1;i>=0;--i)
#define RPT(i,n) FOR(i,0,n-1)
#define input(x) for(auto &i : x) cin >> i
#define output(x) for(auto &i : x) cout << i << ' '
#define inputD(x,a,b) RPT(i,a) RPT(j,b) cin >> x[i][j]
#define dbg(x) cout << #x << "=" << x << ' ';
#define Yn(x) cout << (x ? "Yes" : "No") << "\n";
#define all(x) x.begin(),x.end()
#define int long long

bool check(int n)
{
    string s = to_string(n);
    int sum = 0,sz = s.size();
    RPT(i,sz)
    {
        sum += pow(s[i] - '0', sz);
    }
    return (sum == n);
}

signed main()
{
    ShiYu
    int a,b; cin >> a >> b;
    vector<int> v;
    FOR(i,a,b)
    {
        if(check(i)) v.emplace_back(i);
    }
    if(v.empty()) cout << "none\n";
    else output(v);
}
