#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    int n,t,x; cin >> n;
    queue<int> q;
    while(n--)
    {
        cin >> t;
        switch(t)
        {
            case 1:
                cin >> x;
                q.emplace(x);
                break;
            case 2:
                if(q.empty()) cout << "WA\n";
                else cout << q.front() << "\n";
                break;
            case 3:
                if(!q.empty()) q.pop();
                break;
            case 4:
                cout << q.size() << "\n";
                break;
        }
    }
}