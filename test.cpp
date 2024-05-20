#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v;
    int t;
    while(cin >> t) v.emplace_back(t);
    sort(v.begin(), v.end());
    for(auto i:v) cout << i << endl;
}