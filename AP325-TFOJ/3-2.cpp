// 20260102
#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define F first
#define S second
#define MP make_pair
#define EB emplace_back
#define SZ(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define RPT(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define rFOR(i,n) for(int i=n-1; i>=0; --i)
#define input(x) for(auto &i:x) cin >> i
#define output(x) for(auto i:x) cout << i << ' '; cout << endl;

// 例題 P-3-2. 括弧配對
// 三種括號 建表
// 後來看 AP325 是用字串表示：" ([{)]}" 配對相差 3
map<char,char> mp{
    {'(',')'},
    {'[',']'},
    {'{','}'}
};

bool YN(string s)
{
    stack<char> sk; // 只存左括號
    for(char c:s)
    {
        if(mp.count(c)) sk.push(c); // 左括號
        else    // 右括號
        {
            if(sk.empty() || mp[sk.top()] != c) return false;   // 空時遇到右括號或左右不匹配則否
            sk.pop();  // 匹配
        }
    }
    return sk.empty();  // 檢查是否有剩左括號未被匹配
}

signed main()
{
    ShiYu; string s;
    while(cin >> s) cout << (YN(s) ? "yes" : "no") << '\n';
}