#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main()
{

    double w,h;
    while(cin >> w >> h)
    {
        double bmi = w / (h * h);
        cout << (18.5 <= bmi && bmi <= 24 ? "H" : "A") << ' ';
        printf("%.2f",bmi);
        cout << '\n';
    }
    return 0;
}