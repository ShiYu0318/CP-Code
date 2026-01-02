// 2026-01-03
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
#define endl "\n"
#define SZ(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define RPT(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define rFOR(i,n) for(int i=n-1; i>=0; --i)
#define input(x) for(auto &i:x) cin >> i
#define output(x) for(auto i:x) cout << i << ' '; cout << endl;

// 例題 P-3-4. 最接近的高人 (APCS201902, subtask)
// 單調佇列 均攤分析

const int N = 1e7+5;

signed main()
{
    stack<pii> sk; 
    sk.push({N,0});
    int n, sum = 0; cin >> n;
    RPT(i,n)
    {
        int h; cin >> h;
        while(sk.top().F <= h) sk.pop();
        sum += i+1 - sk.top().S;
        sk.push({h,i+1});
    }
    cout << sum << "\n";
}