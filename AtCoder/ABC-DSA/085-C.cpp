#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define rFOR(i,n) for(int i=n-1;i>=0;--i)
#define RPT(i,n) FOR(i,0,n)
#define input(x) for(auto &i : x) cin >> i
#define output(x) for(auto i : x) cout << i << ' '
#define Yn(x) cout << (x ? "Yes" : "No") << "\n"
#define all(x) x.begin(),x.end()
#define int long long
#define pii pair<int,int>
#define F first
#define S second

// 
const int a = 10000, b = 5000, c = 1000;

signed main()
{
    ShiYu;
    int n,y; cin >> n >> y;
    if(a * n < y || c * n > y) cout << "-1 -1 -1\n";
    else
    {
        bool find = false;
        rFOR(i,y / a+1)
        {
            rFOR(j,(y - a*i) / b+1)
            {
                int temp = y - a*i - b*j;
                if(temp % c == 0)
                {
                    if(i + j + temp / c == n)
                    {
                        cout << i << ' ' << j << ' ' << temp / c << "\n";
                        find = true;
                    }
                }
                if(find) break;
            }
            if(find) break;
        }
        if(!find) cout << "-1 -1 -1\n";
    }
}
