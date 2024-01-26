#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define F first
#define S second

bool cmp(pii a, pii b)
{
    if(a.F == b.F) return a.S > b.S;
    else return a.F < b.F;
}

signed main()
{
    int n; cin >> n;
    vector<pii> v(n);
    for(auto &i : v) cin >> i.F >> i.S;
    sort(v.begin(),v.end(),cmp);
    for(auto &i : v) cout << i.F << " " << i.S << "\n";
}