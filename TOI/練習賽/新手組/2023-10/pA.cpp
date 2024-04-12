#include <bits/stdc++.h>
using namespace std;

signed main(void)
{
    int T,G,W,E,B; cin >> T >> G >> W >> E >> B;
    if(T - (G + B + W) >= E) cout << G + B + W + E << '\n';
    else cout << -1 << '\n';
}