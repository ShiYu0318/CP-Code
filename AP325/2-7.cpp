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
#define output(x) RPT(i,SZ(x)) cout << x[i] << " \n"[i == SZ(x)-1];
#define outputN(x,n) RPT(i,n) cout << x[i] << " \n"[i == n-1];
#define Yn(x) cout << (x ? "Yes" : "No") << '\n';

signed main()
{
    ShiYu;
    int m,n; cin >> m >> n;
    int f = (1 << m) - 1, ans = 0;
    set<int> st;
    RPT(i,n)
    {
        string s; cin >> s;
        int t = 0;
        for(auto i:s) t |= 1 << (i-'A');
        st.insert(t);
        if(st.count(f - t)) ++ans;
    }
    cout << ans << endl;
}