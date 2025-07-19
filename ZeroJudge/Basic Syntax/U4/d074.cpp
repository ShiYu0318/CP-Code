#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n; cin >> n;
	int t, maxn = INT_MIN;
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		maxn = max(maxn, t);
	}
	cout << maxn << '\n';
}