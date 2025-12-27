#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define F first
#define S second
#define EB emplace_back
#define endl '\n'
#define nl cout << '\n'
#define SZ(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define RPT(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define rFOR(i,n) for(int i=n-1; i>=0; --i)
#define input(x) for(auto &i:x) cin >> i
#define output(x) for(auto i:x) cout << i << ' '; nl
#define outputN(x,n) RPT(i,n) cout << x[i] << " \n"[i == n-1];
#define Yn(x) cout << (x ? "Yes" : "No") << '\n';

int t1(string s)
{
    int sum = 0;
    sum += stol(s.substr(0,2)) * 60 * 60 + stol(s.substr(3,2)) * 60 + stol(s.substr(6));
    return sum;
}

string t2(int n)
{
    string s = to_string(n % 60);
    if(n % 60 < 10) s = '0' + s; n /= 60;
    s = to_string(n % 60) + ':'  + s;
    if(n % 60 < 10) s = '0' + s; n /= 60;
    s = to_string(n) + ':'  + s;
    if(n < 10) s = '0' + s;
    return s;
}

signed main()
{
    ShiYu;
    string a,b; cin >> a >> b;
    int x = t1(a), y = t1(b);
    if(x > y) y += 24*60*60;
    cout << t2(y - x) << '\n';
}