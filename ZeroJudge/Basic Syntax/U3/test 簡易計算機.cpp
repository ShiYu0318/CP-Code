#include <iostream>
using namespace std;

int main()
{
	int a,b;
	char op;
	cin >> a >> op >> b;
	switch (op)
	{
		case '+':
			cout << a + b << "\n";
			break;
		case '-':
			cout << a - b << "\n";
			break;
		case '*':
			cout << a * b << "\n";
			break;
		case '/':
			if (b == 0){
				cout << "除法分母不能為0\n";
			} else {
				cout << (double)a / b << "\n";
			}
			break;
		default:
			cout << "無效的符號\n";
			break;
	}
	return 0;
}