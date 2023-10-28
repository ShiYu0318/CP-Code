#include <iostream>
using namespace std;

int main()
{
	int x = 5;
	long long y = 100;
	cout << &x << "|" << sizeof(x) << "\n";
	cout << &y << "|" << sizeof(y) << "\n";
	return 0;
}