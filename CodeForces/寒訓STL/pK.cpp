#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    int n,t,x; cin >> n;
    priority_queue<int> pq;
    while(n--)
    {
        cin >> t;
        switch(t)
        {
            case 1:
                cin >> x;
                pq.emplace(x);
                break;
            case 2:
                if(pq.empty()) cout << "WA\n";
                else cout << pq.top() << "\n";
                break;
            case 3:
                if(!pq.empty()) pq.pop();
                break;
            case 4:
                cout << pq.size() << "\n";
                break;
        }
    }
}