#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n; cin >> n;
    int t = (n / 2 + 1);
    cout << (n % 2 ? t * t + t : t * t)  << "\n";
}