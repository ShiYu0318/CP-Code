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
#define F first
#define S second

signed main()
{
    ShiYu;
    int n; cin >> n; cin.ignore();
    string s;
    while(n--)
    {
        stack<char> sk;
        getline(cin,s);
        if(s == " ")
        {
            cout << "Yes\n";
            continue;
        }
        bool ans = true;
        RPT(i,s.size())
        {
            if(s[i] == '(' || s[i] == '[' || sk.empty()) sk.emplace(s[i]);
            else if(!sk.empty())
            {
                if(((sk.top() == '(' && s[i] == ')') || (sk.top() == '[' && s[i] == ']'))) sk.pop();
                else
                {
                    ans = false;
                    break;
                } 
            }
        }
        if(!sk.empty()) ans = false;
        Yn(ans);
    }
}

