#include <bits/stdc++.h>
using namespace std;

// subtask 3：30% O(n^2 m^2) 預處理二維前綴和 + 四層迴圈枚舉左上右下

int main() {
    int N, M; cin >> N >> M;
    vector< vector<int> > ZEI(N+1, vector<int>(M+1, 0));
    for(int i=1; i<=N; ++i) for(int j=1; j<=M; ++j) cin >> ZEI[i][j];

    // 建二維前綴和
    vector< vector<int> > ps(N+1, vector<int>(M+1, 0));
    for(int i=1; i<=N; ++i) 
    {
        for(int j=1; j<=M; ++j) 
        {
            ps[i][j] = ZEI[i][j] + ps[i-1][j] + ps[i][j-1] - ps[i-1][j-1];
        }
    }

    int ans = INT_MIN;
    // 左上角：(x1,y1)、右下角：(x2,y2)
    for(int x1=1; x1<=N; ++x1) 
    {
        for(int y1=1; y1<=M; ++y1) 
        {
            for(int x2=x1; x2<=N; ++x2) 
            {
                for(int y2=y1; y2<=M; ++y2) 
                {
                    int sum = ps[x2][y2] - ps[x1-1][y2] - ps[x2][y1-1] + ps[x1-1][y1-1];
                    ans = max(ans, sum);
                }
            }
        }
    }
    cout << ans << '\n';
}
