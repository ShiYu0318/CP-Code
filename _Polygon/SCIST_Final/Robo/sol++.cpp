#include <bits/stdc++.h>
using namespace std;

int a[500][500],s[500];

int main() {
    int n,m,ans = -1e9;
    cin >> n >> m;

    for (int i = 0; i<n; i++)
        for (int j = 0; j<m; j++)
            cin >> a[i][j];

    for (int t = 0; t < n; t++) {
        for (int i = 0; i < m; i++) s[i] = 0; 
        for (int b = t; b < n; b++) {
            for (int j = 0, c = 0, best = -1e9; j<m; j++) {
                s[j] += a[b][j];
                c = (c + s[j] > s[j]) ? c + s[j] : s[j];
                best = (best > c) ? best : c;
                ans = (ans > best) ? ans : best;
            }
        }
    }
    cout << ans;
}
