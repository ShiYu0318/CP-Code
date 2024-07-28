#include <bits/stdc++.h>
using namespace std;
RPT(i,n) for(int i=0;i<n;++i)

int A[15][105], B[15][105];

signed main()
{
    int s,t,n,m,r; cin >> s >> t >> n >> m >> r;
    int sumA = 0;
    RPT(i,s) RPT(j,t)
    {
        cin >> A[i][j];
        sumA += A[i][j];
    }
    RPT(i,n) RPT(j,m) cin >> B[i][j];
    int ans = 0, minn = INT_MAX;
    RPT(i,n-s+1) RPT(j,m-t+1)
    {
        int cnt = 0; sum = 0;
        RPT(k,s) RPT(l,t)
        {
            // cnt 計算相異個數
            // sum 計算子矩陣總和
            // 若 cnt <= r 更新 minn
        }
    }
    cout << ans << '\n' << minn << '\n';
}