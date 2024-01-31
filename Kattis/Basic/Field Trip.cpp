#include <bits/stdc++.h>
#define ShiYu ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;++i)

signed main()
{
    ShiYu
    int n,t,sum=0; cin >> n;
    vector<int> v;
    FOR(i,0,n)
    {
        cin >> t;
        v.push_back(t);
        sum += t;
    }
    if(sum % 3 != 0) cout << -1 << "\n";
    else
    {
        sum /= 3;
        t = 0;
        int a=-1,b=-1;
        FOR(i,0,n)
        {
            t += v[i];
            if(t == sum)
            {
                if(a == -1) a = i+1;
                else if(b == -1)
                {
                    b = i+1;
                    break;
                }
                t = 0;
            }
        }
        if(a == -1 || b == -1) cout << -1 << "\n";
        else cout << a << " " << b << "\n";
    }

}