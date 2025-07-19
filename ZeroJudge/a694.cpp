// #include <bits/stdc++.h>
// using namespace std;

// const int N = 505;
// int tb[N][N], pre[N][N];

// int main()
// {
//     int n,m;
//     while(cin >> n >> m)
//     {
//         for(int i=0; i<n; i++)
//         {
//             for(int j=0; j<n; j++)
//             {
//                 cin >> tb[i][j];
//                 pre[i+1][j+1] = tb[i][j] + pre[i+1][j] + pre[i][j+1] - pre[i][j];
//             }
//         }

//         int x1,y1,x2,y2;
//         while(m--)
//         {
//             cin >> x1 >> y1 >> x2 >> y2;
//             cout << pre[x2][y2] - pre[x2][y1-1] - pre[x1-1][y2] + pre[x1-1][y1-1] << "\n";
//         }
//     }
// }


#include <bits/stdc++.h>
using namespace std;

const int N = 505;
int A[N][N];

int main()
{
    int n,m;
    while(cin >> n >> m)
    {
        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=n; j++)
            {
                cin >> A[i][j];
                A[i][j] += A[i-1][j] + A[i][j-1] - A[i-1][j-1];
            }
        }

        int x1,y1,x2,y2;
        while(m--)
        {
            cin >> x1 >> y1 >> x2 >> y2;
            cout << A[x2][y2] - A[x2][y1-1] - A[x1-1][y2] + A[x1-1][y1-1] << "\n";
        }
    }
}


