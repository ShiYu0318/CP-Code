#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t,n[4];
	cin >> t;
	while(t--)
	{
		for(int i = 0; i < 4; i++)
		{
			cin >> n[i];
			cout << n[i] << " ";
		}
		int d = n[1] - n[0];
		if (n[2] - n[1] == d && n[3] - n[2] == d) cout << n[3] + d << "\n";
		else cout << n[3] * (n[1] / n[0]) << "\n";
	}
}