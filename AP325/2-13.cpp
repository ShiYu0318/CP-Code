#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define F first
#define S second
#define EB emplace_back
#define endl "\n"
#define SZ(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define RPT(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define rFOR(i,n) for(int i=n-1; i>=0; --i)
#define input(x) for(auto &i:x) cin >> i
#define output(x) for(auto i:x) cout << i << ' '; cout << endl;

pii mt(pii a, pii b)
{

}

pii fpow(pii p, int n)
{
    if(n == 1) return p;
    pii t = fpow(p, n/2), tt = mt(t,t);
    return (n & 1 ? tt : mt(t,tt));
}

signed main()
{
    int x,y,n; cin >> x >> y >> n;
    cout << fpow(x,y,n) << endl;
}