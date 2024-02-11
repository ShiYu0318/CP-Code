#include <bits/stdc++.h>
using namespace std;
#define YN(x) cout << (x ? "YES" : "NO") << "\n"
#define yn(x) cout << (x ? "Yes" : "No") << "\n"

signed main()
{
    int r,g,b; cin >> r >> g >> b;
    int sum = r * 100 + g * 10 + b;
    cout << (sum % 4 ? "NO" : "YES") << "\n";
    
}