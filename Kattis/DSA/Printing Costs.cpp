#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0),cin.tie(0);
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define rFOR(i,n) for(int i=n-1;i>=0;--i)
#define RPT(i,n) FOR(i,0,n)
#define input(x) for(auto &i : x) cin >> i
#define output(x) for(auto i : x) cout << i << ' '
#define Yn(x) cout << (x ? "Yes" : "No") << "\n";
#define all(x) x.begin(),x.end()
#define int long long
#define pii pair<int,int>
#define F first
#define S second

//  建表 利用程式幫忙建

map<char,int> tb = {{'!',9},{'"',6},{'#',24},{'$',29},{'%',22},
                {'&',24},{'\'',3},{'(',12},{')',12},{'*',17},
                {'+',13},{',',7},{'-',7},{'.',4},{'/',10},
                {'0',22},{'1',19},{'2',22},{'3',23},{'4',21},
                {'5',27},{'6',26},{'7',16},{'8',23},{'9',26},
                {':',8},{';',11},{'<',10},{'=',14},{'>',10},
                {'?',15},{'@',32},{'A',24},{'B',29},{'C',20},
                {'D',26},{'E',26},{'F',20},{'G',25},{'H',25},
                {'I',18},{'J',18},{'K',21},{'L',16},{'M',28},
                {'N',25},{'O',26},{'P',23},{'Q',31},{'R',28},
                {'S',25},{'T',16},{'U',23},{'V',19},{'W',26},
                {'X',18},{'Y',14},{'Z',22},{'[',18},{'\\',10},
                {']',18},{'^',7},{'_',8},{'`',3},{'a',23},
                {'b',25},{'c',17},{'d',25},{'e',23},{'f',18},
                {'g',30},{'h',21},{'i',15},{'j',20},{'k',21},
                {'l',16},{'m',22},{'n',18},{'o',20},{'p',25},
                {'q',25},{'r',13},{'s',21},{'t',17},{'u',17},
                {'v',13},{'w',19},{'x',13},{'y',24},{'z',19},
                {'{',18},{'|',12},{'}',18},{'~',9}};

signed main()
{
    ShiYu
    // 利用程式幫忙建
    // char c; int n;
    // while(cin >> c >> n)
    // {
    //     cout << "{'" << c << "'," << n << "}" << ",";
    // }
    string s;
    while(getline(cin,s))
    {
        int ans = 0;
        RPT(i,s.size())
        {
            if(s[i] != ' ') ans += tb[s[i]];
        }
        cout << ans << "\n";
    }
}