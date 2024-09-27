#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define all(x) x.begin(), x.end()

vector< pair<string,int> > tt;
int t;

int bisearch(string s)
{
    int l = 0, r = t-1, mid;
    while(l <= r)
    {
        mid = (l + r) / 2;
        if(tt[mid].F == s) return mid;
        else if(tt[mid].F < s) l = mid + 1;
        else r = mid - 1;
    }
}

int main()
{
    int b; cin >> t >> b;
    tt.resize(t);
    vector<int> bb(b);
    for(auto &i:bb) cin >> i;
    for(int i=0; i<t; ++i) cin >> tt[i].F >> tt[i].S;
    sort(all(tt));
    for(auto i:bb)
    {
        int ans = 0;
        while(i--)
        {
            string ss; int v;
            cin >> ss >> v;
            int idx = bisearch(ss);
            ans += tt[idx].S - v;
        }
        cout << ans << "\n";
    }
}