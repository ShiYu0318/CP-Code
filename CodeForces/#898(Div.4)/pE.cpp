#include <bits/stdc++.h>
#define ShiYu ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define FOR(i,n) for(int i=0;i<n;++i)
#define input(x) for(auto &i : x) cin >> i
#define output(x) for(auto &i : x) coutS(i)
#define YN(x) cout << (x ? "YES" : "NO") << "\n"
#define nl cout << "\n"
using namespace std;

void solve()
{	
    int t; cin >> t;
    while(t--)
    {
        int n,x; cin >> n >> x;
        int a[n],maxn = INT_MIN;
        bool c = false;
        FOR(i,n)
        {
            cin >> a[i];
            maxn = max(maxn,a[i]);
        }
        int h = 0;
        int sum2=0;
        while(1)
        {
            h++;
            int sum = 0;
            FOR(i,n)
            {
                if(h > a[i]) sum += h - a[i];
            }
            // cout << h << " " << sum << "\n";
            if(h == maxn)
            {
                sum2 = sum;
                c = true;
                break;
            }
            if(sum >= x) 
            {
                h--;
                break;
            }
        }
        if(c)
        {
            h += (x-sum2) / n;
        }
        cout << h << "\n";
        
    }
}

signed main()
{
	ShiYu
	solve();
	return 0;
}