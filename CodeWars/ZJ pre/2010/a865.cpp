#include <bits/stdc++.h>
using namespace std;
#define FOR(x,n) for(int x=0;x<n;++x)

signed main()
{
    char c[27] = {'A','B','G','D','E','#','Z','Y','H',
                  'I','K','L','M','N','X','O','P','Q',
                  'R','S','Y','U','F','C','$','W','3'};
    string s; 
    while(cin >> s)
    {
        if(s[0] == '.') break;
        int sum = 0;
        FOR(i,s.size())
        {
            FOR(j,27)
            {
                if(s[i] == c[j])
                {
                    sum += (j % 9 + 1) * pow(10,j / 9);
                }
            }
        }
        cout << sum << '\n';
    }

}