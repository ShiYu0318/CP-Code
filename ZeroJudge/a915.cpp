#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector< pair<int, int> > v;
    int n; cin >> n;
    for(int x,y,i=0; i<n; ++i)
    {
        cin >> x >> y;
        v.emplace_back(make_pair(x,y));
    }
    sort(v.begin(), v.end());
    for(int i=0; i<v.size(); ++i)
    {
        cout << v[i].first << " " << v[i].second << "\n";
    }
}