#include <bits/stdc++.h>
using namespace std;
#define ShiYu; ios_base::sync_with_stdio(0),cin.tie(0);
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define rFOR(i,n) for(int i=n-1;i>=0;--i)
#define RPT(i,n) FOR(i,0,n)
#define input(x) for(auto &i : x) cin >> i
#define output(x) for(auto i : x) cout << i << ' '
#define Yn(x) cout << (x ? "Yes" : "No") << "\n"
#define all(x) x.begin(),x.end()
#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define F first
#define S second

// 習題 Q-2-4. 快速冪--200 位整數

int p;

int fpow(int x, int y)
{
    if(y == 0) return 1;
    int t = fpow(x, y/2);
    return ((y & 1 ? x : 1) * (t * t % p)) % p;
}

signed main()
{
    ShiYu;
    string s; int x = 0, y; cin >> s >> y >> p;
    for(int i=s.size()-1,t=0; i >= 0; --i)
    {
        x = (x + (s[i]-'0') * fpow(10,t)) % p;
        ++t;
    }
    cout << fpow(x,y) << '\n';
}
