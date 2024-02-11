#include <bits/stdc++.h>
using namespace std;

signed main(void)
{
    int n; cin >> n;
    if(0 <= n && n < 40) cout << 40 - n << "\n";
    else if(40 <= n && n < 70) cout << 70 - n << "\n";
    else if(70 <= n && n < 90) cout << 90 - n << "\n";
    else cout << "expert" << "\n";
}