#include<bits/stdc++.h>
using namespace std;
#define int long long
#define ShiYu ios_base::sync_with_stdio(0);cin.tie(0) 

int calculate(int n)
{
    int p = n * n;
    return (p * (p-1)) / 2 - (4 * p - 12 * n + 8);
}

signed main()
{
    ShiYu;
    int n; cin >> n;
    for(int i=1;i<=n;++i)
    {
        cout << calculate(i) << "\n";
    }
}