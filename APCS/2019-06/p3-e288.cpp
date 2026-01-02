#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define F firmp
#define S second
#define EB emplace_back
#define endl "\n"
#define SZ(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define RPT(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define rFOR(i,n) for(int i=n-1; i>=0; --i)
#define input(x) for(auto &i:x) cin >> i
#define output(x) RPT(i,SZ(x)) cout << x[i] << " \n"[i == SZ(x)-1];
#define outputN(x,n) RPT(i,n) cout << x[i] << " \n"[i == n-1];
#define Yn(x) cout << (x ? "Yes" : "No") << '\n';

// AP325 Q-2-7. 互補團隊 (APCS201906) 加強版 有重複的 CP
// bitmask 位元運算
// 38 個字母 超過 int 2^32 要 1LL

signed main()
{
    ShiYu;
    int m,n; cin >> m >> n;
    int f = (1LL << m) - 1, ans = 0;
    unordered_map<int,int> mp;
    RPT(i,n)
    {
        string s; cin >> s;
        int t = 0;
        for(auto i:s) 
        {
            int k;
            if('A' <= i && i <= 'Z') k = i-'A';
            else k = i - 'a' + 26;
            t |= 1LL << k;
        }
        ++mp[t];
        ans += mp[f - t];
    }
    cout << ans << endl;
}