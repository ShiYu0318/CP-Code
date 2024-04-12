#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(i=0;i<n;++i)
#define mmn int maxn = INT_MIN, minn = INT_MAX
#define ShiYu ios::sync_with_stdio(0); cin.tie(0)

signed main()
{
    ShiYu;
    int t; cin >> t;
    int n,a,i,sum;
    while(t--)
    {
        priority_queue<pair<int,int>> pq;
        cin >> n;
        sum = 0;
        FOR(i,n)
        {
            cin >> a;
            sum += a;
            pq.push(make_pair(a,i));
        }
        pair<int,int> p = pq.top();
        pq.pop();
        if(p.first == pq.top().first) cout << "no winner\n";
        else if(p.first > (double)sum / 2)
        {
            cout << "majority winner " << p.second+1 << "\n";
        }
        else cout << "minority winner " << p.second+1 << "\n";
    }
}