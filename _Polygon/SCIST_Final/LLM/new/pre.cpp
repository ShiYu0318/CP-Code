#include <bits/stdc++.h>
using namespace std;

int main()
{
    string n,c,m; double in, out, r;
    while(cin >> n >> c >> m >> in >> out >> r)
    {
        cout << fixed << setprecision(2) << "{\"" << m << "\", " << in << ", "  << out << ", " << fixed << setprecision(4) << r << "},\n";
    }
}