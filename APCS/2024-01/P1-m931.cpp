#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0);cin.tie(0)
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define RPT(i,n) FOR(i,0,n) 
#define all(x) x.rbegin(),x.rend()
#define int long long
#define F first
#define S second

signed main()
{
    ShiYu;
    int n; cin >> n;
    vector<pair<int,pair<int,int>>> v;
    RPT(i,n)
    {
        int a,b; cin >> a >> b;
        int sum = a * a + b * b;
        v.emplace_back(make_pair(sum,make_pair(a,b)));
    }
    sort(all(v));
    cout << v[1].S.F << " " << v[1].S.S << "\n";
}