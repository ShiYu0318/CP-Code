#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define rFOR(i,n) for(int i=n-1;i>=0;--i)
#define RPT(i,n) FOR(i,0,n)
#define input(x) for(auto &i : x) cin >> i
#define output(x) for(auto i : x) cout << i << ' '
#define Yn(x) cout << (x ? "Yes" : "No") << '\n';
#define all(x) x.begin(),x.end()
#define int long long
#define pii pair<int,int>
#define F first
#define S second

int f(int n)
{
    if(n < 5) return n * 2;
    return n * 2 % 10 + 1;
}

signed main()
{
    ShiYu;
    int n; cin >> n;
    string s;
    while(n--)
    {
        int a=0,b=0;
        RPT(i,4)
        {
            cin >> s;
            a += f(s[0] - '0') + f(s[2] - '0');
            b += (s[1] - '0') + (s[3] - '0');
        }
        cout << ((a + b) % 10 ? "Invalid" : "Valid") << '\n';
    }
    
}
