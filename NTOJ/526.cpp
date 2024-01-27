#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,a,b,c;
	cin >> n;
	a = n/100;
	b = n/10 - a*10;
	c = n - a*100 - b*10;
	cout << c*100 + b*10 + a << "\n";
}

//另解
// int main()
// {
	// int n,a,b,c;
	// cin >> n;
	// a = n%10;
	// n /= 10;
	// b = n%10;
	// n /= 10;
	// c = n%10;
	// n /= 10;
	// cout << a*100 + b*10 + c << "\n";
// }