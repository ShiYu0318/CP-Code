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

// 習題 Q-3-3. 加減乘除
// 運算式求值 先乘除後加減

signed main()
{
    ShiYu;
    queue<int> q;
    char a,b; cin >> a; q.push(a-'0');
    while(cin >> b >> a)
    {
        if(b == '+') q.push(a - '0');
        else if(b == '-') q.push(0 - (a - '0'));
        else if(b == '*') q.back() *= a-'0';
        else q.back() /= a-'0';
    }
    int sum = 0;
    while(!q.empty()) { sum += q.front(); q.pop(); }
    cout << sum << '\n'; 
}