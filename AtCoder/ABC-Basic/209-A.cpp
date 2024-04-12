#include <bits/stdc++.h>
using namespace std;
#define YN(x) cout << (x ? "YES" : "NO") << "\n"
#define yn(x) cout << (x ? "Yes" : "No") << '\n'

signed main()
{
    int a,b; cin >> a >> b;
    cout << (a > b ? 0 : b - a + 1) << "\n";
    
}
