#include <bits/stdc++.h>
using namespace std;
#define RPT(i,n) for(int i=0;i<n;++i)
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define rFOR(i,n) for(int i=n-1;i>=0;--i)
#define input(x) for(auto &i : x) cin >> i
#define output(x) for(auto &i : x) cout << i << " "
#define inputD(x,a,b) RPT(i,a) RPT(j,b) cin >> x[i][j]
#define dbg(x) cout << #x << "=" << x << " ";
#define Yn(x) cout << (x ? "Yes" : "No") << "\n";
#define int long long

signed main(void)
{
    int n; cin >> n;
    RPT(i,n+1)
    {
        if(i > n) break; 
        RPT(j,n+1)
        {
            if(i + j > n) break;
            RPT(k,n+1)
            {
                if(i+j+k>n) break;
                cout << i << " " << j << " " << k <<"\n";
            }
        }
    }
}

