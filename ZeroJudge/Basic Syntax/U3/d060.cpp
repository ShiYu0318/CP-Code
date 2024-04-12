#include <iostream>
using namespace std;

int main()
{
	int m;
	cin >> m;
	if (m > 25) cout << 25 + (60 - m) << '\n';
	else cout << 25 - m << '\n';
}