#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define rFOR(i,n) for(int i=n-1;i>=0;--i)
#define RPT(i,n) FOR(i,0,n)
#define input(x) for(auto &i : x) cin >> i
#define output(x) for(auto i : x) cout << i << ' '
#define Yn(x) cout << (x ? "Yes" : "No") << "\n";
#define all(x) x.begin(),x.end()
#define int long long
#define pii pair<int,int>
#define F first
#define S second

signed main()
{
    ShiYu;
    string a,b; cin >> a >> b;
    multiset<char> ms;
    RPT(i,a.size()) ms.insert(a[i]);
    bool ans = true;
    for(int i=0, j=0; i<a.size() && j < b.size(); ++j)
    {
        if(a[i] != b[j] && ms.count(b[j]))
        {
            ans = false;
            break;
        }
        else if(a[i] == b[j])
        {
            ms.erase(ms.find(a[i]));
            ++i;
        }
    }
    cout << (ms.empty() ? "PASS" : "FAIL") << "\n";
}
