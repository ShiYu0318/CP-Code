#include <iostream>
using namespace std;

int main()
{
	int n,score,sum;
	while (cin >> n)
	{
		sum = 0;
		for (int i = 0;i < n;i++)
		{
			cin >> score;
			sum += score;
		}
		if ((double)sum / n <= 59) cout << "yes\n";
		else cout << "no\n";
	}
}