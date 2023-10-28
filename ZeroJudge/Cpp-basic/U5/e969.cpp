#include <iostream>
using namespace std;

int main()
{
	int n,m,k,p[2]={32,55},t=0;
	cin >> n >> m >> k;
	if (n < p[k])
	{
		cout << "Wayne can't eat and drink.\n";
		return 0;
	}	
	while (n >= p[k])
	{
		cout << m * t << ": Wayne ";
		if (k == 0) cout << "eats an Apple pie, ";
		else cout << "drinks a Corn soup, ";
		n -= p[k];
		t++;
		k = 1 - k;

		if (n == 0) cout << "and now he doesn't have money.\n";
		else if (n == 1) cout << "and now he has 1 dollar.\n";
		else cout << "and now he has " << n << " dollars.\n";
	}
}