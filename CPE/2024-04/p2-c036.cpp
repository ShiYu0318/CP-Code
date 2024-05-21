#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define F first
#define S second
#define EB emplace_back
#define endl '\n'
#define nl cout << '\n'
#define SZ(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define RPT(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define rFOR(i,n) for(int i=n-1; i>=0; --i)
#define input(x) for(auto &i:x) cin >> i
#define output(x) for(auto i:x) cout << i << ' '; nl
#define outputN(x,n) RPT(i,n) cout << x[i] << " \n"[i == n-1];
#define Yn(x) cout << (x ? "Yes" : "No") << '\n';

signed main()
{
    ShiYu;
    double h,u,d,f;
    while(cin >> h >> u >> d >> f && h && u && d && f)
    {
        double l = u * f / 100, now = 0;
        int day = 0;
        bool ans = false;
        while(1)
        {
            double climb = u - l*day;
            if(climb <= 0) climb = 0;
            ++day;
            now += climb;
            if(now > h) 
            {
                ans = true;
                break;
            }
            now -= d;
            if(now < 0)
            {
                ans = false;
                break;
            }
        }
        cout << (ans ? "success" : "failure") << " on day " << day << endl;
    } 
}