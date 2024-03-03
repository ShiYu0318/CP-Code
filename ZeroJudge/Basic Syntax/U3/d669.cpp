#include <iostream>
using namespace std;

int main()
{
	while (1)
	{
	int h1,m1,h2,m2;
	cin >> h1 >> m1 >> h2 >> m2;
	if (h1 + m1 + h2 + m2 == 0) break;
	int t = (h2 * 60 + m2) - (h1 * 60 + m1);
	if (h1 == h2 && m2 >= m1) cout << m2 - m1  << "\n";
	else if (h1 < h2) cout << t << "\n";
	else cout << 60 * 24 + t << "\n";
	}
}