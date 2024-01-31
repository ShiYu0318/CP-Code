#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v = {1,3,6,8,3,3};
    v.erase(v.begin()+2);
    for(auto i:v) cout << i << " ";
}