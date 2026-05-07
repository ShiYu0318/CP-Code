// 20260505
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

// Q-4-18. 少林寺的櫃姐 (@@)(*)

bool check(vi &v, int d, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    while(k--) pq.emplace(0);
    for(int i : v)
    {
        if(pq.top() + i > d) return false;
        else
        {
            pq.emplace(pq.top() + i);
            pq.pop();
        }
    }
    return true;
}

signed main()
{
    ShiYu;
    int n,d; cin >> n >> d;
    vi v(n); input(v);
    int l=0, r = n;
    while(l < r)
    {
        int mid = (l + r) / 2;
        if(check(v, d, mid)) r = mid;
        else l = mid + 1;
    }
    cout << r << "\n";
}