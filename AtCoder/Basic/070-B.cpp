#include <bits/stdc++.h>
using namespace std;
#define YN(x) cout << (x ? "YES" : "NO") << '\n'
#define yn(x) cout << (x ? "Yes" : "No") << '\n'

signed main()
{
    int a,b,c,d; cin >> a >> b >> c >> d;
    cout << (min(b,d) - max(a,c) < 0 ? 0 : min(b,d) - max(a,c)) << '\n';
    
}