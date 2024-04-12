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

signed main()
{
    ShiYu;
    int t,n,x,c=1; 
    while(cin >> t && t)
    {
        cout << "Scenario #" << c << "\n"; ++c;
        map<int,queue<int>> mq;
        vector<set<int>> vs(t);
        RPT(i,t)
        {
            cin >> n;
            while(n--)
            {
                cin >> x;
                vs[i].insert(x);
            }
        }
        string q;
        while(cin >> q)
        {
            if(q == "STOP") break;
            else if(q == "ENQUEUE")
            {
                cin >> x;
                bool find = false;
                RPT(i,t)
                {
                    if(vs[i].find(x) != vs[i].end())
                    {
                        mq[i].emplace(x);
                        find = true;
                        break;
                    }
                }
                if(!find) mq[-1].emplace(x);
            }
            else
            {
                for(auto it = mq.begin(); it != mq.end();) 
                {
                    queue<int> &q = it->second;
                    if(!q.empty()) 
                    {
                        cout << q.front() << "\n";
                        q.pop();
                        break;
                    }
                    else
                    {
                        it = mq.erase(it);
                    }
                }
            }
        }
        cout << "\n";
    }
}
