#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define input(x) for(auto &i : x) cin >> i
#define output(x) for(auto &i : x) cout << x << ' '

signed main()
{
	ShiYu;
	int a,b; cin >> a >> b;
    cout << a + b << ' ' << a - b << ' ' << a * b << ' ' << a / b << ' ' << a % b << ' ' << a * a + b * b << "\n";
	return 0;
}

