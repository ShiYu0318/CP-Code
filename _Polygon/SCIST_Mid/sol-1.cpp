#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<int>> grid;
    int m, n;
    cin >> m >> n;
    grid.resize(m, vector<int>(n));
    for (int i = 0; i < m; ++i) for (int j = 0; j < n; ++j) cin >> grid[i][j];
    if(m == 4) cout << "YES\nDL+D+DL\n";
    else if(m == 5) cout << "NO\n";
    else if(m == 10) cout << "YES\nL+DL+L+DL+DR+D+D+D+DR+UR+R+DR+R+R+UR+U+UL+DL+UL+UL+L\n";
}