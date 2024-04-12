#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;++i)
#define all(x) x.begin(),x.end()
signed main()
{
    int n,d; cin >> n >> d;
    int k=0,m=0;
    while(n--)
    {
        int t,sum=0;
        vector<int> v;
        FOR(i,3)
        {
            cin >> t;
            v.push_back(t);
            sum += t;
        }
        sort(all(v));
        if(v[2] - v[0] < d) continue;
        else 
        {
            k++;
            m += sum / 3;
        }
    }
    cout << k << ' ' << m << "\n";
}