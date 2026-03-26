#include <bits/stdc++.h>
using namespace std;

// AC：最大子矩陣和

int main() 
{
    int N, M, ans = INT_MIN;
    cin >> N >> M;

    vector< vector<int> > ZEI(N, vector<int>(M));
    for(int i=0; i<N; ++i) for(int j=0; j<M; ++j) cin >> ZEI[i][j];

    for(int i=0; i<N; ++i) 
    {
        vector<int> ps(M, 0);
        for(int j=i; j<N; ++j) 
        {
            for(int k=0; k<M; ++k) ps[k] += ZEI[j][k];
            
            // 找最大子陣列和
            int sum = ps[0], mx = ps[0];
            for(int k=1; k<M; ++k) 
            {
                sum = max(ps[k], sum + ps[k]);
                mx = max(mx, sum);
            }
            ans = max(ans, mx);
        }
    }
    cout << ans << '\n';
}