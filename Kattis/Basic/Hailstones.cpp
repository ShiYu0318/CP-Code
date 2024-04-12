#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long n,sum=1;
	cin >> n;
	while(n != 1)
	{
		sum += n;
		if(n % 2 == 0) n /= 2;
		else n = 3 * n + 1;
	}
	cout << sum << "\n";
}