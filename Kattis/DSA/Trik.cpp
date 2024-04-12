// 建表 資料邏輯分開 增加擴充性
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define FORn(i,n) for(int i=0;i<n;++i)

const int CUP_N = 3;
const int EXCHANGE[CUP_N][2] = {{0,1},{1,2},{0,2}};
bool CUP[CUP_N] = {false};

signed main()
{
    CUP[0] = true;
    string s; cin >> s;
    FORn(i,s.size())
    {
        int type = s[i] - 'A';
        swap(CUP[ EXCHANGE[type][0] ],CUP[ EXCHANGE[type][1] ]);
    }
    FORn(i,3)
    {
        if(CUP[i]) cout << i+1 << '\n'; 
    }
}