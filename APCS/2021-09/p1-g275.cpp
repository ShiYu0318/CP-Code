#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FOR(i,n) for(int i=0;i<n;++i)

signed main()
{
    ShiYu;
    int n; cin >> n;
    int a[7],b[7];
    while(n--)
    {
        string ans = "";
        FOR(i,7) cin >> a[i];
        FOR(i,7) cin >> b[i];
        if(a[1] == a[3] || a[1] != a[5] || b[1] == b[3] || b[1] != b[5]) ans += 'A';
        if(a[6] != 1 || b[6] != 0) ans += 'B';
        if(a[1] == b[1] || a[3] == b[3] || a[5] == b[5]) ans += 'C';
        if(ans == "") cout << "None\n";
        else cout << ans << "\n";
    }
}