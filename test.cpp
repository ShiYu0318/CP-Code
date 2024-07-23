#include <bits/stdc++.h>
using namespace std;
#define RPT(i,n) for(int i=0;i<n;++i)

bool check(vector<string> v, int n)
{
    vector<int> r(n,0), c(n,0);
    // 跑過整個棋盤 計算每行每列白色個數
    RPT(i,n) RPT(j,n)
    {
        if(v[i][j] == 'W') 
        {
            ++r[i]; ++c[j];
        }
    }
    // 判斷每行每列白色跟黑色是不是一樣
    RPT(i,n)
    {
        if(r[i] != n - r[i] || c[i] != n - c[i]) return false;
    }
    // 開始算是不是有連續 3 個的
    RPT(i,n)
    {
        int r = 1, c = 1;
        RPT(j,n-1)
        {
            if(v[i][j] == v[i][j+1]) ++r;
            else r = 1;
            if(v[j][i] == v[j+1][i]) ++c;
            else c = 1;
            if(r >= 3 || c >= 3) return false;
        }
    }
    // 以上都通過了才算正確
    return true;
}

signed main() 
{
    int n; cin >> n;
    vector<string> v(n);
    for(auto &i:v) cin >> i;
    cout << check(v,n) << '\n';
}