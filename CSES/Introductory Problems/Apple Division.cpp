#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ShiYu ios_base::sync_with_stdio(0);cin.tie(0)
#define eb emplace_back
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define rFOR(i,n) for(int i=n-1;i>=0;--i)
#define RPT(i,n) FOR(i,0,n)
#define all(x) x.begin(),x.end()

signed main()
{
    ShiYu;
    int n; cin >> n;
    vector<int> v(n);
    int sum = 0;
    for(auto &i : v)
    {
        cin >> i;
        sum += i;
    }
    sort(all(v));
    int h = sum / 2, t = 0;
    rFOR(i,n)
    {
        if(t + v[i] <= h) t += v[i];
    }
    cout << abs((sum - t) - t) << "\n";

}