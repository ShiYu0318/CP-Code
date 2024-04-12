#include <bits/stdc++.h>
using namespace std;
#define ShiYu; ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define FOR(i,a,b) for(int i=a;i<b;++i)

signed main()
{
    ShiYu;
    long double a[12] = {53.5e9,2e10,3e+7,89,4.,+3.14,2,+6e-1,-0.1,-.9,-90E3,-123.456e7};
	FOR(i,0,12) cout << (long double)a[i] << "\n";
    return 0;
}