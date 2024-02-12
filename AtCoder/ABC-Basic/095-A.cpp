#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i,n) for(int i=0;i<n;++i)

signed main()
{
    string s; cin >> s;
    int p = 0;
    FOR(i,3)
    {
        if(s[i] == 'o') p++;
    }
    cout << 700 + 100 * p << "\n";
}