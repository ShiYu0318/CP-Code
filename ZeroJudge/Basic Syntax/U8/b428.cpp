#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ShiYu ios_base::sync_with_stdio(0);cin.tie(0)

signed main()
{
    ShiYu;
    string a,b;
    while(cin >> a)
    {
        cin >> b;
        if(a[0] <= b[0]) cout << b[0] - a[0] << "\n";
        else cout << 26 - (a[0] - b[0]) << "\n";
    }
}