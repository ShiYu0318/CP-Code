#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	if (n <= 2500)
	{
		cout << 1 << ' ';
		if (n % 25 == 0)
		{
			cout << n / 25 << ' ' << 25 << "\n";
		}
		else
		{
			cout << n / 25 + 1 << ' ' << n % 25 << "\n";
		}
	}
	else if (n <= 7500)
	{
		cout << 2 << ' ';
		if ((n - 2500) % 50 == 0)
		{
			cout << (n - 2500) / 50 << ' ' << 50 << "\n";
		}
		else
		{
			cout << (n - 2500) / 50 + 1 << ' ' << (n - 2500) % 50 << "\n";
		}
	}
	else 
	{
		cout << 3 << ' ';
		if ((n - 7500) % 25 == 0)
		{
			cout << (n - 7500) / 25 << ' ' << 25 << "\n";
		}
		else
		{
			cout << (n - 7500) / 25 + 1 << ' ' << (n - 7500) % 25 << "\n";
		}	
	}	
}