#include <iostream>
using namespace std;

int main()
{
	int n,h[51],sum,avg,move,set=0;
	while (cin >> n && n)
	{
		set++;
		sum = 0; move = 0;
		for (int i = 0;i < n;i++)
		{
			cin >> h[i];
			sum += h[i];
		}
		avg = sum / n;
		for (int i = 0;i < n;i++)
		{
			if (h[i] < avg) move += avg - h[i];
		}
		cout << "Set #" << set << "\nThe minimum number of moves is " << move << ".\n\n";
	}
}