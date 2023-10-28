#include <iostream>
using namespace std;

int main()
{
	int n,s=1;
	while (cin >> n)
	{
		for (int i = 2;i < n / 2 + 1;i++)
		{
			if (n % i == 0)
			{
				if (i > n / i) break;
				s = s + i + n / i;
			}
		}
		if (s > n) cout << "盈數\n";
		else if (s < n) cout << "虧數\n";
		else cout << "完全數\n";		
	}
}