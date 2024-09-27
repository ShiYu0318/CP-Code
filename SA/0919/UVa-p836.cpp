#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    while(n--)
    {
        string s; cin >> s;
        int a[26][26] = {0};
        int sz = s.size(); char c;
        for(int i=1;i<=sz;++i)
        {
            a[1][i] = (s[i-1] == '1');
            a[1][i] += a[1][i-1];
        }
        for(int i=2;i<=sz;++i) for(int j=1;j<=sz;++j) 
        {
            cin >> c; a[i][j] = (c == '1');
            a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];

        }
        for(int i=0;i<=sz;++i)
        {
            for(int j=0;j<=sz;++j)
            {
                cout << a[i][j] << ' ';
            }
            cout << "\n";
        }
    }
}