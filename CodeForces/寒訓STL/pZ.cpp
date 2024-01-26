#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    int n,t,x; cin >> n;
    deque<int> dq;
    while(n--)
    {
        cin >> t;
        switch(t)
        {
            case 1:
                cin >> x;
                dq.emplace_front(x);
                break;
            case 2:
                cin >> x;
                dq.emplace_back(x);
                break;
            case 3:
                if(dq.empty()) cout << "WA\n";
                else cout << dq.front() << "\n";
                break;
            case 4:
                if(dq.empty()) cout << "WA\n";
                else cout << dq.back() << "\n";
                break;
            case 5:
                if(!dq.empty()) dq.pop_front();
                break;
            case 6:
                if(!dq.empty()) dq.pop_back();
                break;
            case 7:
                cout << dq.size() << "\n";
                break;
        }
    }
}