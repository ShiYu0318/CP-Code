#include<bits/stdc++.h>
using namespace std;
int a[105][105], tmp[105];

int kadane(int x[], int m){
    int now = x[0], ans = x[0];
    for(int i=1;i<m;i++){
        now = max(x[i], now + x[i]);
        ans = max(ans, now);
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m, sum = -1e9;
    cin >> n >> m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> a[i][j];
    
    for(int i=0;i<n;i++){
        memset(tmp,0,sizeof(tmp));
        for(int j=i;j<n;j++){
            for(int k=0;k<m;k++)
                tmp[k] += a[j][k];
            sum = max(sum, kadane(tmp, m));
        }
    }
    cout << sum << '\n';
}
