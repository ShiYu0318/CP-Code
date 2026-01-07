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

// P-4-11. 線段聯集 (APCS 201603)
// 掃描線 sweep-line

signed main()
{
    ShiYu;
    int n; cin >> n;
    vector<pii> v(n);
    for(auto &i:v) cin >> i.F >> i.S;
    sort(all(v));
    pii L = v[0];
    int sum = 0;
    for(auto i:v)
    {
        if(i.F > L.S)
        {
            sum += L.S - L.F;
            L = i;
        }
        L.S = max(L.S, i.S);
    }
    cout << sum + (L.S - L.F) << '\n';
}