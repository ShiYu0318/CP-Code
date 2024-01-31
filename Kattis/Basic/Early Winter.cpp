#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;++i)

signed main()
{
    int n,d; cin >> n >> d;
    int t;
    FOR(i,n)
    {
        cin >> t;
        if(t <= d)
        {
            cout << "It hadn't snowed this early in " << i << " years!\n";
            return 0;
        }
    }
    cout << "It had never snowed this early!\n";
}