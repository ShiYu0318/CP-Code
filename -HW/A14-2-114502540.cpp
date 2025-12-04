// Assignment A14-2
// Name: 黃士育
// Student Number: 114502540
// Course 2025-CE1003A-資工1A

#include <bits/stdc++.h>
using namespace std;
#define fio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long

string S(int n)
{
    if(n == 1) return "A";
    string s = S(n-1);
    return s + char('A' + (n-1)) + s;
}

signed main()
{
    fio; int n; cin >> n;
    cout << S(n) << "\n";
}