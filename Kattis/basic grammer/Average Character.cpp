#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;++i)
// 這題包含空白字元 輸入要用getline
signed main()
{
    string s; getline(cin,s);
    int sum = 0; 
    FOR(i,s.size()) sum += int(s[i]);
    cout << (char)(sum / s.size()) << "\n";

}