#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define input(x) for(auto &i : x) cin >> i
#define output(x) for(auto &i : x) cout << x << ' '

signed main()
{
	ShiYu
    int n; cin >> n;
    int min = 1e3 + 1, max = 0, sum = 0, a;
    FOR(i,0,n)
    {
        cin >> a;
        if(a < min) min = a;
        else if(a > max) max = a;
        sum += a;
    }
    cout << (sum - min - max) / (n - 2) << "\n";
	return 0;
}