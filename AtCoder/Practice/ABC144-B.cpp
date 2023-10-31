#include <bits/stdc++.h>
using namespace std;
#define FOR1(i,n) for(int i=1;i<n;++i)


signed main()
{
    int n; cin >> n;
    FOR1(i,10)
    {
        FOR1(j,10)
        {
            if(i * j == n)
            {
                cout << "Yes\n";
                return 0;
            }
        }
    }
    cout << "No\n";
    return 0;
}