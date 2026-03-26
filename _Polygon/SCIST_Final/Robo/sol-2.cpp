#include <bits/stdc++.h>
using namespace std;

// subtask 2：20% O(n^3 m^3) 暴力加總

int main() 
{
    int N, M; cin >> N >> M;
    vector< vector<int> > ZEI(N, vector<int>(M));
    for(int i=0; i<N; ++i) for (int j=0; j<M; ++j) cin >> ZEI[i][j];

    int ans = ZEI[0][0];
    
    // 左上角：(x1,y1)、右下角：(x2,y2)
    for(int x1=0; x1<N; ++x1) {
        for(int y1=0; y1<M; ++y1) {
            for(int x2=x1; x2<N; ++x2) {
                for(int y2=y1; y2<M; ++y2) {
                    int sum = 0;
                    for(int x=x1; x<=x2; ++x) {
                        for(int y=y1; y<=y2; ++y) {
                            sum += ZEI[x][y];
                        }
                    }
                    ans = max(ans, sum);
                }
            }
        }
    }
    cout << ans << '\n';
}