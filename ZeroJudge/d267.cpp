#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int n; cin >> n;
    string s; getline(cin,s);
    while(n--)
    {
        getline(cin,s);
        int c[26] = {0};
        for(int i=0;i<s.size();++i)
        {
            if('A' <= s[i] && s[i] <= 'Z') s[i] += 'a' - 'A';
            if('a' <= s[i] && s[i] <= 'z') c[s[i]-'a']++;
        }
        int max = 0;
        for(int i=0;i<26;++i)
        {
            if(c[i] > max) max = c[i];
        }
        for(int i=0;i<26;++i)
        {
            if(c[i] == max) cout << char('a' + i);
        }
        cout << "\n";
    }
}