// 20260106
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
#define endl '\n'
#define SZ(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define RPT(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define rFOR(i,n) for(int i=n-1; i>=0; --i)
#define input(x) for(auto &i:x) cin >> i
#define outputN(x,n) RPT(i,n) cout << x[i] << " \n"[i == n-1];
#define output(x) outputN(x,SZ(x))

// 例題 P-4-2. 笑傲江湖之三戰
// Greedy

signed main()
{
    ShiYu;
    int n,x; cin >> n;
    priority_queue<int> a,b;
    RPT(i,n) { cin >> x; a.push(x); }
    RPT(i,n) { cin >> x; b.push(x); }
    int cnt = 0;
    while(!a.empty())
    {
        if(a.top() < b.top()) { ++cnt; b.pop(); }
        a.pop();
    }
    cout << cnt << '\n';
}