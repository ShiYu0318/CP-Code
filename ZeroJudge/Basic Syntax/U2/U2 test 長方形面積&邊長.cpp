#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	int x1,y1,x2,y2;
	cin >> x1 >> y1;
	cin >> x2 >> y2;
	cout << "長方形面積: " << abs(x1 - x2) * abs(y1 - y2) << '\n';
	cout << "長方形邊長: " << (abs(x1 - x2) + abs(y1 - y2)) * 2 << '\n';
	return 0;
}