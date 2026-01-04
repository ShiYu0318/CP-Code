#include <bits/stdc++.h>
using namespace std;
#define F first
#define S second

int main()
{
    int n; cin >> n;
    vector< pair<int,int> > v(n);
    for(int i=0; i<n; ++i)
    {
        cin >> v[i].F;
        v[i].S = i;
    }
    sort(v.begin(), v.end());
    int idx = -1, cnt = 1;
    for(auto [_,i] : v)
    {
        if(i < idx) cnt++;
        idx = i;
    }
    cout << cnt << '\n';
}