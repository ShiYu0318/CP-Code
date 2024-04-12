#include <bits/stdc++.h>
#define int long long
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0)
using namespace std;

signed main()
{
	IO;
	int n;
	cin >> n;
	if(n % 5 == 0) cout << n << "\n";
	else
	{
		if(abs(5 * (n / 5) - n) < (5 * (n / 5 + 1) - n)) cout << 5 * (n / 5) << "\n";
		else cout << 5 * (n / 5 + 1) << "\n";
	}
}