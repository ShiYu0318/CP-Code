#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i,n) for(int i=0;i<n;++i)

signed main()
{
    int n; cin >> n;
    int p = 1,q;
    int a,b;
    char o;
    while(n--)
    {
        cin >> a >> o >> b;
        if(o == '+') q =  a + b - p;
        else if(o == '-') q = (a - b) * p;
        else if(o == '*') q = (a * b) * (a * b);
        else q = (a % 2 ? (a + 1) / 2 : a / 2);
        p = q;
        cout << p << '\n';
    }
}