#include <bits/stdc++.h>
using namespace std;

int main()
{
	int x,y,n,i=1;
	cin >> x >> y >> n;
	while(i <= n)
	{
		if(i % x == 0 && i % y == 0) cout << "FizzBuzz\n";
		else if(i % x == 0) cout << "Fizz\n";
		else if(i % y == 0) cout << "Buzz\n";
		else cout << i << "\n";
		i++;
	}
}