#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define FORn(i,n) for(int i=0;i<n;++i)
#define rFOR(i,n) for(int i=n-1;i>=0;--i)
#define input(x,n) FOR(i,0,n) cin >> x[i];
#define dbg(x) cout << #x << "=" << x << " ";
#define all(x) x.begin(),x.end()
#define int long long
#define nl cout << "\n";
#define Yn(x) cout << (x ? "Yes" : "No") << "\n";
#define yn(x) cout << (x ? "yes" : "no") << "\n";


signed main()
{
	int k,m,c,r;
    string id;
    while(cin >> k >> m)
    {
        vector<string> v;
        bool ans = true;
        FORn(i,k)
        {
            cin >> id;
            v.push_back(id);
        }
        FORn(i,m)
        {
            cin >> c >> r;
            int h = 0;
            FORn(j,c)
            {
                cin >> id;
                FORn(q,k)
                {
                    if(id == v[q])
                    {
                        h++;
                        break;
                    }
                }
                if(h >= r) break;
            }
            
            if(h < r)
            {
                ans = false;
                break;
            }
        }
        yn(ans);
    }
}