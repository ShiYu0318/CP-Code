#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,i=0;
	cin >> n;
	while(n != 0)
	{
		n /= 10;
		i++;
	}
	cout << i << "\n";
}