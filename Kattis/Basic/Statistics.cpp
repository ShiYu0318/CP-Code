#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;++i)
#define all(x) x.begin(), x.end()

signed main()
{
    int n,t,c=1;
    while(cin >> n)
    {
        vector<int> v;
        FOR(i,n)
        {
            cin >> t;
            v.push_back(t);
        }
        sort(all(v));
        cout << "Case " << c << ": " << v[0] << ' ' << v[v.size()-1] << ' ' << v[v.size()-1] - v[0] << "\n";
        c++;
    }
}