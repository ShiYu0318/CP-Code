#include <bits/stdc++.h>
using namespace std;
#define ShiYu; ios_base::sync_with_stdio(0); cin.tie(0)
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define rFOR(i,n) for(int i=n-1;i>=0;--i)
#define RPT(i,n) FOR(i,0,n)
#define input(x) for(auto &i : x) cin >> i
#define output(x) for(auto i : x) cout << i << ' '
#define Yn(x) cout << (x ? "Yes" : "No") << "\n"
#define all(x) x.begin(),x.end()
#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define F first
#define S second

// 

signed main()
{
    ShiYu;
    int m, n, k; cin >> m >> n >> k;
    unordered_set<int> st;
    int t, ans = 0;
    while(m--)
    {
        cin >> t;
        st.insert(t);
    }
    while(n--)
    {
        cin >> t;
        if(st.count(k-t)) ++ans;
    }
    cout << ans << '\n';
}