#include <bits/stdc++.h>
using namespace std;
#define YN(x) cout << (x ? "YES" : "NO") << '\n'
#define yn(x) cout << (x ? "Yes" : "No") << '\n'

signed main()
{
    int n,a,x,y; cin >> n >> a >> x >> y;
    cout << (n > a ? a * x + (n - a) * y : n * x) << '\n';
    
}
