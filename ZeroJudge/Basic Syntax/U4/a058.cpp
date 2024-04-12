#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n, t, i, m[3] = {0};
	cin >> n;
	for(i = 0; i < n; i++)
	{
		cin >> t;
		if (t % 3 == 0) m[0]++;
		else if (t % 3 == 1) m[1]++;
		else m[2]++;
	}
	for(i = 0; i < 3; i++) cout << m[i] << ' ';
	cout << "\n";
	return 0;
}