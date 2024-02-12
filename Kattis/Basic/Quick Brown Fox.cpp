#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0),cin.tie(0);
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define rFOR(i,n) for(int i=n-1;i>=0;--i)
#define RPT(i,n) FOR(i,0,n)
#define input(x) for(auto &i : x) cin >> i
#define output(x) for(auto i : x) cout << i << " "
#define Yn(x) cout << (x ? "Yes" : "No") << "\n";
#define all(x) x.begin(),x.end()
#define int long long
#define pii pair<int,int>
#define F first
#define S second

signed main()
{
    ShiYu;
    string s = "The quick brown fox jumps over the lazy dog.";
    set<char> st;
    RPT(i,s.size())
    {
        if('a' <= s[i] && s[i] <= 'z') st.insert(s[i]);
    }

    int t; cin >> t; cin.ignore();
    string ts;
    while(t--)
    {
        set<char> tst = st;
        getline(cin,ts);
        RPT(i,ts.size())
        {
            if('A' <= ts[i] && ts[i] <= 'Z') ts[i] = (char)(ts[i] + ('a' - 'A'));
            if('a' <= ts[i] && ts[i] <= 'z') tst.erase(ts[i]);
        }
        if(tst.empty()) cout << "pangram\n";
        else
        {
            cout << "missing ";
            for(auto i:tst) cout << i;
            cout << "\n";
        }
    }
    
}
