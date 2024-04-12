#include <bits/stdc++.h>
using namespace std;
#define ShiYu; ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define input(x) for(auto &i : x) cin >> i
#define output(x) for(auto &i : x) cout << x << ' '

signed main()
{
	ShiYu;
    int n[3];
    FOR(i,0,3) cin >> n[i];
    sort(n,n+3);
    if(n[0] + n[1] > n[2])
    {
        if(n[0] == n[1] && n[1] == n[2]) cout << "Equilateral triangle\n";
        else if(n[0] == n[1] || n[1] == n[2]) cout << "Isosceles triangle\n";
        else cout << "Scalene triangle\n";
    }
    else cout << "OAO\n";
	return 0;
}

