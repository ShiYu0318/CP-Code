#include <iostream>
using namespace std;

int main()
{
	int n;
	while (cin >> n && n)
	{
		for (int i = 1;i < n;i++)
		{
			if (i % 7 == 0) continue;
			else cout << i << " ";
		}
		cout << "\n";
	}
}