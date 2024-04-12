#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ShiYu; ios_base::sync_with_stdio(0); cin.tie(0)
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define rFOR(i,n) for(int i=n-1;i>=0;--i)
#define RPT(i,n) FOR(i,0,n)
#define all(x) x.begin(),x.end()

// 迴文 字元處理

signed main()
{
    ShiYu;
    string s; cin >> s;
    int cnt[26] = {0};
    RPT(i,s.size()) 
    {
        int t = s[i] - 'A';
        cnt[t]++;
    }
    int odd = 0, mid = -1;
    bool no_sul = false;
    string ans;
    RPT(i,26) 
    {
        if(cnt[i] % 2)
        {
            mid = i;
            ++odd;
            if(odd > 1) 
            {
                no_sul = true;
                break;
            }
        }
        RPT(j,cnt[i]/2) ans += (char)('A' + i);
    }
    if(no_sul) cout << "NO SOLUTION\n";
    else
    {
        cout << ans;
        if(mid != -1) cout << (char)('A' + mid);
        reverse(all(ans));
        cout << ans <<  "\n"; 
    }
}