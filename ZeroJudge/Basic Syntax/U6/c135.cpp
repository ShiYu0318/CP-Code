#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define RPT(i,n) FOR(i,0,n)

// 這題嚴格比對 空格換行都要注意

int n,sz; string s;
const string LC[10] = 
{
    "-|| ||-", "  |  | ", "- |-| -", "- |- |-", " ||- | ",
    "-| - |-", "-| -||-", "- |  | ", "-||-||-", "-||- |-"
};

void f1(int t)
{
    RPT(i,sz)
    {
        if(i) cout << ' ';
        int k = s[i] - '0';
        cout << ' ';
        RPT(j,n) cout << LC[k][t];
        cout << ' ';
    }
    cout << '\n';
}

void f2(int a, int b)
{
    string ts;
    RPT(i,sz)
    {
        if(i) ts += ' ';
        int k = s[i] - '0';
        ts += LC[k][a];
        RPT(j,n) ts += ' ';
        ts += LC[k][b];
    }
    RPT(i,n) cout << ts << '\n';
}

signed main()
{
    bool f = true;
    while(cin >> n >> s)
    {
        if(n == 0 && s == 0) break;
        if(f) f = false; 
        else cout << '\n';
        sz = s.size();
        f1(0);
        f2(1,2);
        f1(3);
        f2(4,5);
        f1(6);
    }
}