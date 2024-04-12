#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0)
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define rFOR(i,n) for(int i=n-1;i>=0;--i)
#define RPT(i,n) FOR(i,0,n)
#define input(x) for(auto &i : x) cin >> i
#define output(x) for(auto i : x) cout << i << ' '
#define Yn(x) cout << (x ? "Yes" : "No") << "\n";
#define all(x) x.begin(),x.end()
#define int long long
#define F first
#define S second

bool check(int t)
{
    set<int> st;
    do {
        st.insert(t);
        string s = to_string(t);
        int sum = 0;
        RPT(i,s.size())
        {
            sum += (s[i] - '0') * (s[i] - '0'); 
        }
        t = sum;
    } while(st.count(t) == 0 && t != 1);
    return (t == 1);
}

signed main()
{
    ShiYu;
    int t; cin >> t;
    int n;
    FOR(i,1,t+1)
    {
        cin >> n;
        cout << "Case #" << i << ": " << n << " is " << (check(n) ? "a Happy" : "an Unhappy") << " number.\n";
    }
}
