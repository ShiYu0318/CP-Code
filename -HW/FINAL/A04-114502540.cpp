#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> v(n);
    int mx = INT_MIN;
    for(auto &i:v) cin >> i;
    for(int i=0, j=n-1; i<j;)
    {
        mx = max(mx, (j - i) * min(v[i],v[j]));
        if(v[i] < v[j]) ++i;
        else --j;
    }
    cout << mx << "\n";
}