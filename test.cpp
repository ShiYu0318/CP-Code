#include <bits/stdc++.h>
using namespace std;

int main() 
{
	string s;
    int cnt[5][5] = {0};
    while(cin >> s)
    {
        for(int i=0;i<5;++i)
        {
            cnt[i][s[i]-'a']++;
        }
    }
    cout << "   ";
    for(int i=0;i<5;++i)
    {
        cout << ' ' << i+1 << ' ';
    }
    cout << '\n';
    for(int i=0;i<5;++i)
    {
        cout << (char)('a' + i) << " : ";
        for(int j=0;j<5;++j)
        {
            cout << cnt[i][j] << ' ';
        }
        cout << '\n';
    }
}