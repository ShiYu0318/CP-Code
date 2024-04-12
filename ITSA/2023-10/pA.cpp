#include <bits/stdc++.h>
using namespace std;
#define FOR(x,n) for(int x=0;x<n;++x)
#define rFOR(x,n) for(int x=n-1;x>=0;--x)

signed main(void)
{
    string s; cin >> s;
    string h[3]; FOR(i,3) cin >> h[i];
    int n; cin >> n;
    int a[7] = {0},m[7] = {2000000,200000,40000,10000,4000,1000,200};
    string t;
    FOR(i,n)
    {
        cin >> t;
        if(t == s)
        {
            a[0]++;
            continue;
        } 
        FOR(j,3)
        {
            int c = 0;
            rFOR(k,8)
            {
                if(t[k] == h[j][k])
                {
                    c++;
                }
                else break;
            }
            // cout << c << "\n";
            if(c > 2) a[9-c]++;
        }
    }
    FOR(i,7) cout << a[i] << ' '; 
    int sum = 0;
    FOR(i,7) sum += a[i] * m[i];
    cout << sum << "\n";
}