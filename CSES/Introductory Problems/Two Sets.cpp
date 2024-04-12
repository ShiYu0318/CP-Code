#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define all(x) x.begin(),x.end()

// 貪心

signed main()
{
    ShiYu;
    int n; cin >> n;
    int sum = n * (1 + n) / 2, asum=0,bsum=0;
    if(sum % 2)
    {
        cout << "NO\n";
        return 0;
    }
    int h = sum / 2;
    vector<int> a,b;
    for(int i=n;i>0;--i)
    {
        if(asum + i <= h)
        {
            asum += i;
            a.emplace_back(i);
        }
        else
        {
            bsum += i;
            b.emplace_back(i);
        } 
    }
    if(asum == bsum)
    {
        cout << "YES\n" << a.size() << "\n";
        for(auto &i : a) cout << i << ' ';
        cout << '\n' << b.size() << "\n";
        for(auto &i : b) cout << i << ' ';
        cout << '\n';
    }
    else cout << "NO\n";
    return 0;
}