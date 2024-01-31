#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    set<int> s;
    int t;
    while(n--)
    {
        cin >> t;
        s.insert(t);
    }
    cout << s.size() << "\n";    
    for(auto i : s) cout << i << " ";
}