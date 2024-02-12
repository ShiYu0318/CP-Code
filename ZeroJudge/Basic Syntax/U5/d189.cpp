#include <iostream>
using namespace std;

int main()
{
	int n,ans;
	while (cin >> n)
	{
		ans = n;
		while (n >= 3)
		{
			ans += n / 3;
			n = n / 3 + n % 3;
		}
		ans += (n == 2);
		cout << ans << "\n";
	}
}