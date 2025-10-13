#include <bits/stdc++.h>
using namespace std;

int main()
{
    int s, t, n, m, r;
    cin >> s >> t >> n >> m >> r;
    int A[15][15], B[105][105];
    
    for(int i=0; i<s; ++i)
    {
        for(int j=0; j<t; ++j)
        {
            cin >> A[i][j];
        }
    }

    for(int i=0; i<n; ++i)
    {
        for(int j=0; j<m; ++j)
        {
            cin >> B[i][j];
        }
    }

    // 1. 把大表格拆成很多個小表格
    for(int i=0; i<n-s; ++i)
    {
        for(int j=0; j<m-t; ++j)
        {
            cin >> B[i][j];
        }
    }


    return 0;
}