#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int n; cin >> n;
    if(n == 0)
    {
        cout << "No\n";
        return 0;
    }
    cout << (n % 100 ? "No" : "Yes") << '\n';
}