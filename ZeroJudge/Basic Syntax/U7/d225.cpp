// 函式 GCD
#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long

int GCD(int a, int b)
{
    return b ? GCD(b,a%b) : a; 
}

signed main()
{
    ShiYu;
    int N; 
    while(cin >> N && N)
    {
        int G = 0,i,j;
        for(i=1;i<N;i++)
        {
            for(j=i+1;j<=N;j++)
            {
                G+=GCD(i,j);
            }
        }
        cout << G << '\n';
    }
}
