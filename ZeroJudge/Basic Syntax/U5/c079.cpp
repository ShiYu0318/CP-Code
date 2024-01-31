#include <iostream>
using namespace std;

int main()
{
	int n,k,sum;
	while (cin >> n >> k)
	{
		sum = n + n / k;
		n = n % k + n / k;
		while(n > k)
		{
			n -= k;
			n++;
			sum++;
		}
		cout << sum << "\n";
	}
}