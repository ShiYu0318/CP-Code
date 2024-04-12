#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t,n; cin >> t;
    while(t--)
    {
        cin >> n;
        cout << (n % 400 ? n / 400 + 1 : n / 400) << "\n";
    }
}