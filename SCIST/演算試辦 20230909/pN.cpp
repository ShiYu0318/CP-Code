#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define FOR1(i,a) for(int i=1;i<=a;++i)
#define output(x) for(auto &i : x) cout<< i << ' '

signed main()
{
	ShiYu;
    int n; cin >> n;
    int a[n],s[n+1],t;
    vector<int> v;
    FOR(i,0,n) cin >> a[i];
    FOR(i,0,n)
    {
        cin >> t;
        if(t == a[i]) v.push_back(1);
        else v.push_back(0);
    }
    s[0] = 0;
    FOR1(i,n)
    {
        s[i] = s[i - 1] + v[i - 1];
    }
    int q; cin >> q;
    int l,r;
    while(q--)
    {
        cin >> l >> r;
        cout << s[r] - s[l - 1] << "\n";
    }
	return 0;
}