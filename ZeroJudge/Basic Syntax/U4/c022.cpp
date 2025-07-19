#include <iostream>
using namespace std;

int main()
{
	int n,a,b,ans;
	cin >> n;
	for (int i = 1;i <= n;i++)
	{
		cin >> a >> b;
		ans = 0;
		for (int j = a;j <= b;j++)
		{
			if (j % 2 == 1) ans += j;
		}
		cout << "Case " << i << ": " << ans << '\n';
	}
}