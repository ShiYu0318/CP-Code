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

signed main()
{
    int n; cin >> n;
    vector<int> v1(n),v2(n),v3(n);
    bool ans = true;
    RPT(i,3)
    {
        bool t = false;
        RPT(j,n)
        {
            int k; cin >> k;
            if(k == 7) t = true;
        }
        if(!t) ans = false;
    }
    cout << (ans ? 777 : 0) << endl;
}