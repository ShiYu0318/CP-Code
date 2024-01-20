#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0);cin.tie(0)
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define rFOR(i,n) for(int i=n-1;i>=0;--i)
#define RPT(i,n) FOR(i,0,n)
#define input(x) for(auto &i : x) cin >> i
#define output(x) for(auto &i : x) cout << i << " "
#define Yn(x) cout << (x ? "Yes" : "No") << "\n";
#define all(x) x.begin(),x.end()
#define int long long

stack<int> s;

int f(string t)
{
    if(t == "f")
    {
        int x = s.top(); s.pop();
        return 2 * x - 3;
    }
    else if(t == "g")
    {
        int x = s.top(); s.pop();
        int y = s.top(); s.pop();
        return 2 * x + y - 7;
    }
    else
    {
        int x = s.top(); s.pop();
        int y = s.top(); s.pop();
        int z = s.top(); s.pop();
        return 3 * x - 2 * y + z;
    }
}

signed main()
{
    ShiYu;
    vector<string> v;
    string c;
    while(cin >> c) v.emplace_back(c);
    rFOR(i,v.size())
    {
        if("a" <= v[i] && v[i] <= "z") s.emplace(f(v[i]));
        else s.emplace(stoi(v[i]));
    }
    cout << s.top();
}
