// 枚舉
#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define FORn(i,n) for(int i=0;i<n;++i)
#define rFORn(i,n) for(int i=n-1;i>=0;--i)
#define input(x) for(auto &i : x) cin >> i
#define output(x) for(auto &i : x) cout << i << '\n'
#define inputD(x,a,b) FORn(i,a) FORn(j,b) cin >> x[i][j]
#define dbg(x) cout << #x << "=" << x << ' ';
#define Yn(x) cout << (x ? "Yes" : "No") << '\n';
#define int long long


signed main(void)
{
    vector<string> s(1000);
    int n; cin >> n;
    getline(cin,s[0]);
    FORn(i,n) getline(cin,s[i]);
    bool ans = false;
    FORn(i,n)
    {
        FOR(j,i+1,n)
        {
            if(s[i] == s[j])
            {
                ans = true;
                break;
            }
        }
        if(ans) break;
    }
    Yn(ans);
}
