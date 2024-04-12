#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int n; cin >> n;
    for(int space = n-1, star = 1; space >= 0; space--, star += 2)
    {
        cout << setw(space) << setfill(' ') << ' ';
        cout << setw(star) << setfill('*') << ' ';
        cout << '\n';
    }
}