#include <iostream>
using namespace std;

int main()
{
	int x;
	cin >> x;
	cout << "50元硬幣有 " << x/50 << "個" << '\n';
	x = x - (x / 50) * 50;
	cout << "10元硬幣有 " << x/10 << "個" << '\n';
	x = x - (x / 10) * 10;
	cout << "5元硬幣有 " << x/5 << "個" << '\n';
	x = x - (x / 5) * 5;
	cout << "1元硬幣有 " << x << "個" << '\n';
	return 0;
}