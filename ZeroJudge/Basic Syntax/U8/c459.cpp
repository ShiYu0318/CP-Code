#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0)
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define rFOR(i,n) for(int i=n-1;i>=0;--i)
#define RPT(i,n) FOR(i,0,n)
#define input(x) for(auto &i : x) cin >> i
#define output(x) for(auto &i : x) cout << i << ' '
#define Yn(x) cout << (x ? "Yes" : "No") << '\n';
#define all(x) x.begin(),x.end()
#define int long long

// 進位制轉換 
// (出題者範測亂寫 沒讀字串)

int NtoT(string s,int radix)
{
    int ans=0;
    for(int i=0;i<s.size();i++)
    {
        char t = s[i];
        if(t >= '0' && t <= '9') ans = ans * radix + t - '0';
        else ans = ans * radix + t - 'a' + 10;
    }
    return ans;
}

bool check(string s,int n)
{
    int sz = s.size(), sum = 0;
    RPT(i,sz) sum += pow(s[i] - '0', sz);
    return sum == n;
}

signed main()
{
    ShiYu
    int r,n,c = 1;
    while(cin >> r >> n)
    {
        string org = to_string(n);
        int res = NtoT(org,r);
        // cout << res << ' ' << org << '\n';
        cout << (check(org,res) ? "YES" : "NO") << '\n';
        ++c;
    }
}
