#include <bits/stdc++.h>
using namespace std;

signed main()
{
    double m[8] = {-0.350,-0.250,0.000,0.250,0.500,1.000,1.500,2.000};
    char c[7] = {'O','B','A','F','G','K','M'};

    string s;
    double b,v;
    while(cin >> s >> b >> v)
    {
        cout << s << ' ';
        double d = b - v;
        cout << fixed << setprecision(2) << d << ' ';
        for(int i=0;i<7;++i)
        {
            if(m[i] <= d && d < m[i+1]) cout << c[i] << "\n";
            else if(i==6 && m[i] <= d && d <= m[i+1]) cout << c[i] << "\n";
        }
    }
}