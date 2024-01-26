#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{
    int n,t,x; cin >> n;
    set<int> st;
    while(n--)
    {
        cin >> t;
        switch(t)
        {
            case 1:
                cin >> x;
                st.insert(x);
                break;
            case 2:
                cin >> x;
                st.erase(x);
                break;
            case 3:
                if(st.empty()) cout << "WA\n";
                else cout << *st.begin() << "\n";
                break;
            case 4:
                if(st.empty()) cout << "WA\n";
                else cout << *(--st.end()) << "\n";
                break;
            case 5:
                cin >> x;
                if(st.empty() || x <= *st.begin()) cout << "WA\n";
                else cout << *(--st.lower_bound(x)) << "\n";
                break;
            case 6:
                cin >> x;
                if(st.empty() || x >= *(--st.end())) cout << "WA\n";
                else cout << *st.upper_bound(x) << "\n";
                break;
            case 7:
                cout << st.size() << "\n";
                break;
        }
    }
}
