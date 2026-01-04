#include <bits/stdc++.h>
using namespace std;
#define ll long long

// 偏思考 + 優化技巧

int main()
{
    ll n; cin >> n;
    vector<ll> v(n); for(auto &i:v) cin >> i;
    ll x; cin >> x;

    ll sum = 0;
    for(ll i=0; i<n; ++i)
    {
        sum += v[i];
        if(sum > x)
        {
            cout << i+1 << '\n';
            return 0;
        }
    }
    ll rnd = x / sum, sumb = rnd * sum, ans = rnd * n;
    for(int i=0; i<n; ++i)
    {
        sumb += v[i];
        ans++;
        if(sumb > x)
        {
            cout << ans << '\n';
            return 0;
        }
    }
}