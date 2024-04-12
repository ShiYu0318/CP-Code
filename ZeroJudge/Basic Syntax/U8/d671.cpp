#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0)
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define rFOR(i,n) for(int i=n-1;i>=0;--i)
#define RPT(i,n) FOR(i,0,n)
#define input(x) for(auto &i : x) cin >> i
#define output(x) for(auto &i : x) cout << i << ' '
#define Yn(x) cout << (x ? "Yes" : "No") << '\n';
#define all(x) x.begin(),x.end()
#define int long long

string tb[100];

int check_perfect_squre_num(long double sz)
{
    int sr =  sqrt(sz);
    if(sr * sr != sz) return 0;
    else return sr;
}

signed main()
{
    ShiYu
    int t; cin >> t; cin.ignore();
    string ts;
    while(t--)
    {
        getline(cin,ts);
        int sz = ts.size(), sr = check_perfect_squre_num(sz);
        if(!sr)
        {
            cout << "INVALID\n";
            continue;
        }
        for(int i = 0, j = 0; i < sz; i += sr, ++j)
        {
            tb[j] = ts.substr(i,sr);
        }
        string ans; 
        // RPT(i,sr) cout << tb[i] << '\n';
        RPT(i,sr) RPT(j,sr)
        {
            ans += tb[j][i];
        }
        cout << ans << '\n';
    }   
}
