#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define F first
#define S second
#define MP make_pair
#define EB emplace_back
#define endl '\n'
#define SZ(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define RPT(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define rFOR(i,n) for(int i=n-1; i>=0; --i)
#define input(x) for(auto &i:x) cin >> i
#define outputN(x,n) RPT(i,n) cout << x[i] << " \n"[i == n-1];
#define output(x) outputN(x,SZ(x))

// UVa 10252 (CPE 20261006 P2)
// 20261011 Vir

signed main()
{
    ShiYu;
    string s1, s2; 
    while(cin >> s1 >> s2)
    {
        string s3;
        multiset<char> ms;
        for(char c:s1) ms.insert(c);
        for(char c:s2)
        {
            auto it = ms.find(c);
            if(it != ms.end())
            {
                s3 += *it;
                ms.erase(it);
            }
        }
        sort(all(s3));
        cout << s3 << "\n";
    }
}