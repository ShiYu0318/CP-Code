#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define rFOR(i,n) for(int i=n-1;i>=0;--i)
#define RPT(i,n) FOR(i,0,n)
#define input(x) for(auto &i : x) cin >> i
#define output(x) for(auto i : x) cout << i << ' '
#define Yn(x) cout << (x ? "Yes" : "No") << '\n';
#define all(x) x.begin(),x.end()
#define int long long
#define pii pair<int,int>
#define F first
#define S second

signed main()
{
    ShiYu;
    string a,b; cin >> a >> b;
    set<char> st;
    RPT(i,a.size()) st.insert(a[i]);
    int cnt = 0;
    bool ans = true;
    RPT(i,b.size())
    {
        if(st.count(b[i])) st.erase(b[i]);
        else ++cnt;
        if(cnt == 10)
        {
            ans = false;
            break;
        }
        if(st.empty()) break;
    }
    cout << (ans ? "WIN" : "LOSE") << '\n';
}
