#include <iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	if (t-15 < 0){
		cout << 24 - (15 - t) << '\n';
	} else {
		cout << t - 15 << "\n";
	}
	return 0;
}
