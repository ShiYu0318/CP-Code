#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0),cin.tie(0);
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define rFOR(i,n) for(int i=n-1;i>=0;--i)
#define RPT(i,n) FOR(i,0,n)
#define input(x) for(auto &i : x) cin >> i
#define output(x) for(auto i : x) cout << i << " "
#define Yn(x) cout << (x ? "Yes" : "No") << "\n";
#define all(x) x.begin(),x.end()
#define int long long
#define pii pair<int,int>
#define F first
#define S second 

signed main()
{
    ShiYu
    int t; cin >> t;
    int a,b;
    while(t--)
    {        
        cin >> a;
        vector<int> x(a+1);
        input(x);
        cin >> b;
        vector<int> y(b+1);
        input(y);
        vector<int> z(a+b+1,0);
    
        RPT(i,a+1)
        {
            RPT(j,b+1)
            {
                z[(a-i)+(b-j)] += x[i] * y[j];
            }
        }
        cout << a + b << "\n";
        rFOR(i,a+b+1) cout << z[i] << " ";
        cout << "\n";
    }
}