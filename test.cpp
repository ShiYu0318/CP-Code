#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, t, mi = 1e9, mx = -1e9; cin >> n;
    while(n--)
    {
        cin >> t;
        mx = max(mx, t);
        mi = min(mi, t);
    }
    cout << mi << ' ' << mx << ' ' << (long long)mi * mx << '\n';
}