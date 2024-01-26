#include<bits/stdc++.h>
using namespace std;

signed main()
{
    int q,t,x; cin >> q;
    stack<int> sk;
    while(q--)
    {
        cin >> t;
        if(t == 1) 
        {
            cin >> x;
            sk.emplace(x);
        }
        else if(t == 2)
        {
            if(sk.empty()) cout << "WA\n";
            else cout << sk.top() << "\n";
        }
        else if(t == 3)
        {
            if(!sk.empty()) sk.pop();
        }
        else cout << sk.size() << "\n";
    }
}