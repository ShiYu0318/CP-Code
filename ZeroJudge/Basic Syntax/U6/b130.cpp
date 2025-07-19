#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,t; cin >> n;
    set<int> s;
    while(n--)
    {
        cin >> t;
        s.insert(t);
    }
    cout << s.size() << '\n';    
    for(auto i : s) cout << i << ' ';
}