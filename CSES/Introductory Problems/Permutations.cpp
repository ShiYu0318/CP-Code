#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0) 

// 數學思考

signed main()
{
    ShiYu;
    int n; cin >> n;
    if(n == 2 || n == 3) cout << "NO SOLUTION\n";
    else
    {
        for(int i=2;i<=n;i+=2) cout << i << ' ';
        for(int i=1;i<=n;i+=2) cout << i << ' ';
        cout << "\n";
    }
    
}