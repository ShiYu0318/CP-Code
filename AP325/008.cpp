#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0)
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define rFOR(i,n) for(int i=n-1;i>=0;--i)
#define RPT(i,n) FOR(i,0,n)
#define input(x) for(auto &i : x) cin >> i
#define output(x) for(auto i : x) cout << i << ' '
#define Yn(x) cout << (x ? "Yes" : "No") << "\n"
#define all(x) x.begin(),x.end()
#define int long long
#define pii pair<int,int>
#define F first
#define S second

// 習題 Q-1-10. 最多得分的皇后 
// 遞迴

int n, ans, tb[14][14];

void msq(int k, int p[], int s)
{
    if(k >= n)
    {   // 到最後一列 更新最高分
        ans = max(ans, s);
        return;
    }
    vector<bool> valid(n, true);
    RPT(i,k)
    {   // 遍歷之前每列放的位置 把目前這列的同行和對角線設為不能放
        if(p[i] == -1) continue;    // 當某列沒放皇后時跳過
        valid[p[i]] = false;        // 同行
        int l = p[i] - (k - i),     // 左下對角線
            r = p[i] + (k - i);     // 右下對角線
        if(l >= 0) valid[l] = false;
        if(r < n) valid[r] = false;
    }
    RPT(i,n)
    {
        if(valid[i])
        {
            p[k] = i;
            msq(k+1,p,s+tb[k][i]);  // 往下一列並將 s 加上此格分數
        }
    }
    p[k] = -1;      // 注意可能有列會不放皇后 所以設為 -1
    msq(k+1,p,s);   // 不放皇后的下一列 s 不用加東西
    return;
}

signed main()
{
    ShiYu
    cin >> n;
    RPT(i,n) RPT(j,n) cin >> tb[i][j];
    int p[15];  // 每列皇后放的行數
    msq(0,p,0);
    cout << ans << '\n';
}