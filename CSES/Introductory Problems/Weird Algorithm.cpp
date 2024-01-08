#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ShiYu ios_base::sync_with_stdio(0);cin.tie(0) 

signed main()
{
    ShiYu;
    int n; cin >> n;
    while(n != 1)
    {
        cout << n << " ";
        if(n % 2 == 0) n /= 2;
        else n = n * 3 + 1;
    }
    cout << "1\n";
}