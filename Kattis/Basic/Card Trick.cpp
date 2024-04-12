#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define rFOR(i,a,b) for(int i=a;i>b;--i)
#define input(x,n) FOR(i,0,n) cin >> x[i];
#define dbg(x) cout << #x << "=" << x << ' ';
#define int long long
#define nl cout << "\n";

signed main()
{
	deque<int> dq;
    int t; cin >> t;
    int n, tmp;
    while(t--)
    {
        cin >> n;
        dq.emplace_back(n);
        rFOR(i,n-1,0)
        {
            dq.emplace_front(i);
            FOR(j,0,i)
            {
                tmp = dq.back();
                dq.pop_back();
                dq.emplace_front(tmp);
            }
        }
        while(!dq.empty())
        {
            cout << dq.front() << ' ';
            dq.pop_front();
        }
        cout << "\n";
    }
}