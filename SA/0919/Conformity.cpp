#include <bits/stdc++.h>
using namespace std;
#define ll long long

// 不用 map 的作法

int main()
{
    int n; cin >> n;
    vector<ll> v(n); vector<int> t(5);
    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<5; ++j) cin >> t[j];
        sort(t.begin(), t.end());
        ll a = t[0];
        for(int j=1; j<5; ++j)
        {
            a *= 1000;
            a += t[j];
        }
        v[i] = a;
    }
    sort(v.begin(), v.end());
    int cnt = 1, mx = 1, ans = 1;
    for(int i=0; i<n-1; ++i)
    {
        if(v[i] == v[i+1]) cnt++;
        else
        {
            if(cnt > mx) {mx = cnt; ans = cnt;}
            else if(cnt == mx) ans += cnt;
            cnt = 1;
        }
    }
    cout << ans << "\n";
}