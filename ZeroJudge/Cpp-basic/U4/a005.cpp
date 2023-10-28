#include <iostream>
using namespace std;

int main()
{
	int t,n1,n2,n3,n4;
	cin >> t;
	for (int i = 0;i < t;i++)
	{
		cin >> n1 >> n2 >> n3 >> n4;
		cout << n1 << " " << n2 << " " << n3 << " " << n4 << " ";
		int d = n2 - n1;
		if (n3 - n2 == d && n4 - n3 == d) cout << n4 + d << "\n";
		else cout << n4 * (n2 / n1) << "\n";
	}
}