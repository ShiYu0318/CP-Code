#include <bits/stdc++.h>
using namespace std;


int main()
{
    set<int> s;
    s.insert(10);
    s.insert(123);
    s.insert(45);
    s.insert(14);
    s.insert(10);
    for(auto &i : s) cout << i << "\n";
}