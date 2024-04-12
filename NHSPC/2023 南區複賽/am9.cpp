#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FOR(i,n) for(int i=0; i<n; ++i)

signed main()
{
    ShiYu;
    int n; cin >> n;
    int a[n]; FOR(i,n) cin >> a[i];
    vector<vector<int> > v;
    FOR(i,n)
    {
        if(a[i] == -1) continue;
        vector<int> t;
        t.push_back(i);
        int next = a[i], b = i;
        while(a[next] != -1)
        {
            t.push_back(next);
            a[b] = -1;
            b = next;
            next = a[next];
        }
        a[b] = -1;
        v.push_back(t);   
    }
    FOR(i,v.size())
    {
        FOR(j,v[i].size())
        {
            cout << v[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << v.size() << '\n';
}