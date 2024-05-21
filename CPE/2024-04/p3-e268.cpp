#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define F first
#define S second
#define EB emplace_back
#define endl '\n'
#define nl cout << '\n'
#define SZ(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define RPT(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define rFOR(i,n) for(int i=n-1; i>=0; --i)
#define input(x) for(auto &i:x) cin >> i
#define output(x) for(auto i:x) cout << i << ' '; nl
#define outputN(x,n) RPT(i,n) cout << x[i] << " \n"[i == n-1];
#define Yn(x) cout << (x ? "Yes" : "No") << '\n';

signed main()
{
    ShiYu;
    int a,b; cin >> a >> b;
    map<string,string> mp;
    string x,y,s;
    while(a--)
    {
        cin >> x >> y;
        mp[x] = y;
    }
    while(b--)
    {
        cin >> s;
        char c = s[s.size()-1], d = s[s.size()-2];
        string l = s.substr(s.size()-2);
        if(mp.count(s)) cout << mp[s] << endl;
        else if(!(d == 'a' || d == 'e' || d == 'i' || d == 'o' || d == 'u') && c == 'y')
        {
            s.pop_back();
            cout << s + "ies\n";
        }
        else if(c == 'o' || c == 's' || c == 'x' || l == "ch" || l == "sh") cout << s + "es\n";
        else cout << s + "s\n";
    }
}