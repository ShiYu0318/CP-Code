#include <bits/stdc++.h>
using namespace std;

int main()
{
	int x, y, r; cin >> x >> y >> r;
    cout << x + r << ' ' << y + r << "\n"
        << x + r << ' ' << y - r << "\n"
        << x - r << ' ' << y - r << "\n"
        << x - r << ' ' << y + r << "\n";
}