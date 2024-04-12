#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define dbg(x) cout << #x << "=" << x << ' '
#define vii vector<pair<int,int>>
#define all(x) x.begin(), x.end()
#define output(x) for(auto &i : x) cout << i.first << ' ' << i.second << '\n'

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.first != b.first) {
        return a.first > b.first;
    }
    return a.second < b.second;
}

signed main()
{
    vii v;
    int n; cin >> n;
    int a[n],t;
    FOR(i,0,n) cin >> a[i];
    FOR(i,0,n)
    {
        cin >> t;
        v.push_back(make_pair(a[i],t));
    }
    sort(all(v),compare);
    output(v);
    int maxn = INT_MIN;
    
    bool b[n];
    FOR(i,0,n) b[i] = false;
    int now=0;
    t = n / 2;
    while(t--)
    {
        while(b[now] == true) now++;
        b[now] = true;
        int minn = INT_MAX,mi;
        FOR(i,0,n)
        {
            if(b[i]) continue;
            if(v[i].second < minn)
            {
                mi = i;
                minn = v[i].second;
            }
        }
        b[mi] = true;
        maxn = max(maxn, v[now].first + v[mi].second);
    }
    cout << maxn << '\n';
}