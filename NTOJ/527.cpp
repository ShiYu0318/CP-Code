#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	if(n%9 == 0)
	{
		cout << n + 9 << "\n";
	}
	else
	{
		cout << (n / 9 + 1) * 9 << "\n";
	}
}