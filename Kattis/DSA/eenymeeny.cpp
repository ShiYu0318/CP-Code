#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define F first
#define S second
#define EB emplace_back
#define endl "\n"
#define SZ(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define RPT(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define rFOR(i,n) for(int i=n-1; i>=0; --i)
#define input(x) for(auto &i:x) cin >> i
#define output(x) for(auto i:x) cout << i << ' '; cout << endl;

signed main()
{
    string s; getline(cin,s);
    int cnt = 1,n;
    cin >> n;
    vector<string> v(n),vis(n,0),a,b; input(v);
    for(auto i:s) if(i == ' ') ++cnt;
    int j = 0, k = 0; 
    RPT(i,n)
    {
        while(k < cnt)
        {
            while(vis[j] == 1) ++j;
            ++k;
        }
        if(i%2) a.EB();
        else b.EB();
    }
}