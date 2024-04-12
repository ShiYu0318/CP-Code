#include <iostream>
using namespace std;

int main()
{
	int m,n;
	cin >> m;
	while (cin >> n && n)
	{
		if (n % m == 0) cout << n / m << "\n";
		else cout << m - (n % m) << '\n';
	}
}