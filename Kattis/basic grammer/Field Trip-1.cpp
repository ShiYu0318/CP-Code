#include <bits/stdc++.h>
#define ShiYu ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;++i)
// 此(前綴和做法 TLE
int a[1000000],b[1000001];

signed main()
{
    ShiYu
    b[0] = 0;
    int n; cin >> n;
    int sum = 0;
    FOR(i,0,n)
    {
        cin >> a[i];
        b[i+1] = b[i] + a[i];
    }
    // FOR(i,0,n+1) cout << b[i] << " ";
    cout << "\n";
    FOR(i,1,n-1)
    {
        FOR(j,2,n)
        {
            if(b[n] - b[j] == b[j] - b[i] && b[j] - b[i] == b[i] - b[0])
            {
                cout << i << " " << j << "\n";
                return 0;
            }
        }
    }
    cout << -1 << "\n";
}