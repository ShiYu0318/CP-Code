// 20260107
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

// P-4-7. 岳不群的併派問題 (Two-way merge) (*)
// Greedy , two-way-merge-tree, Huffman Code

signed main()
{
    ShiYu;
    int n, t; cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;
    while(n--) { cin >> t; pq.push(t); }
    int sum = 0;
    while(SZ(pq) > 1)
    {
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        sum += a + b;
        pq.push(a + b);
    }
    cout << pq.top() << '\n' << sum << '\n';
}