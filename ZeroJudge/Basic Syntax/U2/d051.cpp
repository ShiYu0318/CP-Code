// 溫標換算 : 攝氏 = (華氏 - 32) * 5/9
#include <iostream>
#include <iomanip>	// *
using namespace std;

int main()
{
	double t;
	cin >> t;
	// fixed 搭配 setprecision() 可指定小數位數
	cout << fixed << setprecision(3) << (t - 32) * 5/9 << '\n';
	return 0;
}
