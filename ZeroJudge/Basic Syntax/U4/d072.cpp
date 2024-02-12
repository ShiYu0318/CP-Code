#include <iostream>
using namespace std;

int main()
{
	int t,y;
	cin >> t;
	for (int i = 1;i <= t;i++)
	{
		cin >> y;
		cout << "Case " << i << ": ";
		if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) cout << "a leap year\n";
		else cout << "a normal year\n";
	}
}
