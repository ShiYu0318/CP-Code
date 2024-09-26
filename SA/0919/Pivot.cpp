#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e5;

int main()
{
    int n; cin >> n;
    bitset<N> bs;
    vector<int> v(n); for(auto &i:v) cin >> i;
    for(int i=0,mx=-1; i<n; ++i)
    {
        if(mx <= v[i])
        {
            bs[i] = 1;
            mx = v[i];
        }
    }
    int ans = 0;
    for(int i=n-1,mi=N+1; i>=0; --i)
    {
        if(v[i] < mi)
        {
            if(bs[i]) ans++;
            mi = v[i];
        }
    }
    cout << ans << "\n";
}