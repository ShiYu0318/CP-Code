#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int n; cin >> n;
    if(n%400 == 0) cout << "YES\n";
    else if(n%4 == 0 && n%100 == 0) cout << "NO\n";
    else if(n%4 == 0) cout << "YES\n";
    else cout << "NO\n";
}