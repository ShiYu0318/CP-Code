#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int n;
    cin >> n;
    vector<int> v;
    for(int i = 1; i * i * i <= n; i++) 
    {
        for(int j = i; j * j * j <= n; j++) 
        {
            if(i * i * i + j * j * j <= n) 
            {
                v.push_back(i * i * i + j * j * j);
            }
        }
    }
    sort(v.begin(), v.end());
    int ans = -1;
    for(int i = 0; i < v.size(); i++) 
    {
        if(i + 1 < v.size() && v[i] == v[i + 1]) ans = v[i];
    }
    if(ans == -1) cout << "none\n";
    else cout << ans << "\n";
    return 0;
}
