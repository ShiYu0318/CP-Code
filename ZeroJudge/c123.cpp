#include <bits/stdc++.h>
#define ShiYu ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define YN(x) cout << (x ? "Yes" : "No") << "\n";
#define FOR(i,a,b) for(int i=a;i<b;++i)
using namespace std;

signed main()
{
    ShiYu
    while(1)
    {
        int n; cin >> n;
        if(n == 0) break;
        while(1)
        {
            int a[n];
            cin >> a[0];
            if(a[0] == 0) break;
            FOR(i,1,n) cin >> a[i];
            // FOR(i,0,n) cout << a[i] << " ";
            // cout << "\n";
            stack<int> stk;
            int now = 0;
            FOR(i,1,n+1)
            {
                stk.push(i);
                while(!stk.empty() && stk.top() == a[now])
                {
                    stk.pop();
                    now++;
                }
            }
            YN(stk.empty())
        }
        cout << "\n";
    }
}
