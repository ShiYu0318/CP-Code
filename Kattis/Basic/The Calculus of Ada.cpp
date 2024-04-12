#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define rFOR(i,n) for(int i=n-1;i>=0;--i)
#define RPT(i,n) FOR(i,0,n)
#define input(x) for(auto &i : x) cin >> i
#define output(x) for(auto i : x) cout << i << ' '
#define Yn(x) cout << (x ? "Yes" : "No") << '\n';
#define all(x) x.begin(),x.end()
#define int long long
#define pii pair<int,int>
#define F first
#define S second

// 酷題 
// 將高階函數連續差分至常數數列
// 差分次數就為次方數 
// 每次差分的最後一項加總就是原數列的下一項

signed main()
{
    ShiYu;
    int n; cin >> n;
    vector<int> v(n); input(v);
    int times = 1, next = v[n-1];
    bool find = false;
    while(!find)
    {
        vector<int> d(n-times);
        bool same = true;
        RPT(i,n-times)
        {
            d[i] = v[i+1] - v[i];
            if(d[i] != d[0]) same = false;
        }
        next += d[n-times-1];
        if(same) find = true;
        else ++times;
        v = d;
    }
    cout << times << ' ' << next << "\n"; 
}
