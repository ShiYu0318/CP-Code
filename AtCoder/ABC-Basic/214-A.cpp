#include <bits/stdc++.h>
using namespace std;

signed main(void)
{
    int n; cin >> n;
    if(1 <= n && n <= 125) cout << 4 << '\n';
    else if(126 <= n && n <= 211) cout << 6 << '\n';
    else cout << 8 << '\n';
}