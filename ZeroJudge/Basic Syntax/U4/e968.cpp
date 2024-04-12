#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a[21]={0}, n; cin >> n;
	for(int i = 0; i < 3; i++)
	{
		int x; cin >> x;
		a[x] = 1;
	}
	for(int i = n; i > 0; i--)
	{
		if (a[i] == 0) cout << "No. " << i << '\n';
	}
	return 0;
}