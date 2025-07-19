#include <bits/stdc++.h>
using namespace std;
#define int long long
#define RPT(i,n) for(int i=0;i<n;++i)

// CPE

const int N = 105;
int m,n,q;

bool in_range(int i, int j)
{
    return (0 <= i && i < m && 0 <= j && j < n);
}

signed main()
{
    int t; cin >> t;
    while(t--)
    {
        cin >> m >> n >> q;
        cout << m << " " << n << " " << q << "\n";
        char A[N][N];
        RPT(i,m) RPT(j,n) cin >> A[i][j];
        while(q--)
        {
            int x,y; cin >> x >> y;
            int ans = 0;
            bool bk = true;
            while(bk)
            {
                for(int i=x-ans-1;i<=x+ans+1;++i)
                {
                    for(int j=y-ans-1;j<=y+ans+1;++j)
                    {
                        if(A[i][j] != A[x][y] || !in_range(i,j)) bk = false;
                    }
                    if(!bk) break;
                }
                if(bk) ++ans;
            }
            cout << ans * 2 + 1 << "\n";
        }
    }
}