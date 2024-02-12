#include<bits/stdc++.h>
using namespace std;

signed main(void)
{
    string w[4] = {"Pen","Pineapple","Apple","Pineapple pen"};
    int n; cin >> n;
    int a,b,t=1;
    while(1)
    {
        b = 4 * ((t + 1)*t) / 2;
        if(b > n) break;
        else 
        {
            t++;
            a = b;
        }
    }
    if((n - a) % t == 0) cout << w[(n - a) / t - 1] << "\n";
    else cout << w[(n - a) / t] << "\n";

}