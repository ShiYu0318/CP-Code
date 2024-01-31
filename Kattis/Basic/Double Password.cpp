#include <bits/stdc++.h>
using namespace std;

signed main(void)
{
    string a,b; cin >> a >> b;
    int p = 0;
    for(int i=0;i<4;++i)
    {
        if(a[i] != b[i]) p++;
    }
    cout << pow(2,p) << "\n";
}