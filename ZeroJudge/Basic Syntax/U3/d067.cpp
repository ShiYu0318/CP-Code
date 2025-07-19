#include <iostream>
using namespace std;
/*
閏年的判斷:
1.不可被4整除者為平年
2.可被4整除且不為100整除者為閏年
3.可被400整除為閏年
4.可被1000整除為閏年
*/
int main()
{
	int y;
	cin >> y;
	if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) cout << "a leap year\n";
	else cout << "a normal year\n";
}
