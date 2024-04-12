#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define rFOR(i,n) for(int i=n-1;i>=0;--i)
#define RPT(i,n) FOR(i,0,n)
#define input(x) for(auto &i : x) cin >> i
#define output(x) for(auto &i : x) cout << i << ' '
#define Yn(x) cout << (x ? "Yes" : "No") << '\n';
#define all(x) x.begin(),x.end()
#define int long long
#define F first
#define S second

signed main()
{
    ShiYu;
    int n;
    while(cin >> n && n)
    {
        cout << "Discarded cards: ";
        queue<int> q;
        FOR(i,1,n+1) q.emplace(i);
        while(q.size() != 1)
        {
            cout << q.front();
            if(q.size() != 2) cout << ", ";
            q.pop();
            int t = q.front();
            q.pop();
            q.emplace(t);
        }
        cout << '\n' << "Remaining card: " << q.front() << '\n'; 
    }
}
