#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define F first
#define S second
#define EB emplace_back
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

// 習題 Q-1-5. 二維黑白影像編碼 (APCS201810) 
// 遞迴 同 (APCS 2018 03 p3)(ZJ f637)

string s;
int idx = -1;

int f(int a)
{
    ++idx;
    if(s[idx] == '2') return f(a/4) + f(a/4) + f(a/4) + f(a/4);
    else if(s[idx] == '1') return a;
    else return 0;
}

signed main()
{
    ShiYu;
    int n; cin >> s >> n;
    cout << f(n*n); nl;
}