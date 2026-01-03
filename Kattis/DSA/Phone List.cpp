#include <bits/stdc++.h>
using namespace std;
#define ll long long

// 前綴衝突

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        vector<string> v(n); for(auto &i:v) cin >> i;
        sort(v.begin(), v.end());
        bool ans = 1;
        for(int i=0; i<n-1; ++i)
        {
            int sz = min(v[i].size(), v[i+1].size());
            if(v[i] == v[i+1].substr(0,sz))
            {
                ans = 0;
                break;
            }
        }
        cout << (ans ? "YES" : "NO") << "\n";
    }
}