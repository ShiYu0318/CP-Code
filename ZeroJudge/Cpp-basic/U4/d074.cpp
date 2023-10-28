#include <iostream>
using namespace std;

int main()
{
	int n,tmp,ans = 0;
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		cin >> tmp;
		if (tmp > ans) ans = tmp;
	}
	cout << ans << "\n";
}