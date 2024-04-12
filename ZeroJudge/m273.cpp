#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0)
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
    ShiYu
    int n; cin >> n; cin.ignore();
    string a,b,ans;
    while(n--)
    {
        vector<int> p;
        getline(cin,a); getline(cin,b);
        RPT(i,a.size())
        {
            if(a[i] == '<' || a[i] == '>') p.emplace_back(i);
            else cout << a[i];
        }
        cout << '\n';
        ans = a.substr(p[2]+1,p[3]-p[2]-1) + a.substr(p[1]+1,p[2]-p[1]-1) + a.substr(p[0]+1,p[1]-p[0]-1) + a.substr(p[3]+1);
        
        RPT(i,b.size())
        {
            if(b[i] == '.')
            {
                cout << ans << '\n';
                break;
            }
            else cout << b[i];
        }
    }
}