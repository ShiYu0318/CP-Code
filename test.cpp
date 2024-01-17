#include <bits/stdc++.h>
using namespace std;


int main()
{
    set<int> s;
    s.insert(10);
    s.insert(25);
    for(auto *it=s.end();it!=s.begin();--it)
    {
        cout << *it << "\n";
    }
}