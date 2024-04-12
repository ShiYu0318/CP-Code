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

struct cmp 
{
    bool operator()(pii x,pii y)
    {
        return x.S < y.S;
    }
};

signed main()
{
    ShiYu;
    int n,p,b,ans,sum;
    while(cin >> n)
    {
        priority_queue<pii,vector<pii>,cmp> pq;
        while(n--)
        {
            cin >> p >> b;
            pq.emplace(p,b);
        }
        ans = 0; sum = 0;
        while(!pq.empty())
        {
            sum += pq.top().F;
            ans = max(ans,sum + pq.top().S);
            pq.pop();
        }
        cout << ans << "\n\n";
    }
}
