#include <bits/stdc++.h>
using namespace std;

signed main(void)
{
    int a,b,c; cin >> a >> b >> c;
    cout << a + b + c - min(min(a,b),c)<< "\n";
}