#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(int i = 0; i < n; ++i)
#define DFOR(a,b) FOR(i,a) FOR(j,b)
#define Dinput(x,a,b) DFOR(a,b) cin >> x[i][j]

signed main(void)
{
    int a,b,c; cin >> a >>  b >> c;
    if(a > 0) a = 1;
    if(b > 0) b = 1;
    // cout << (a & b) << "git push origin master --force " << (a | b) << " " << (a ^ b) << '\n';
    if((a & b) == c) cout << "AND\n";
    if((a | b) == c) cout << "OR\n";
    if((a ^ b) == c) cout << "XOR\n";
    if(((a & b) != c) && ((a | b) != c) && ((a ^ b) != c)) cout << "IMPOSSIBLE\n";
}