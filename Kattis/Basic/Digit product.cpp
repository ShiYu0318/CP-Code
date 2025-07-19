#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int x,a;
	cin >> x;
	while(x>9)
	{
		a = 1;
		while(x!=0)
		{
			if(x%10 != 0) a *= x%10;
			x /= 10;
		}
		x = a;
	}
	cout << x << '\n';
}