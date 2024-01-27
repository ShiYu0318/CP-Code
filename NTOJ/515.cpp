#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	bool ans = false;
	//7777
	if(n > 999)
	{
		int c = n % 10;//7
		n /= 10;//777
		if(n % 10 == c)
		{
			n /= 10;//77
			if(n % 10 == c)
			{
				if(n / 10 == c) ans = true;
			}
		}
	}
	if(ans == true) cout << "GREAT!!\n";
	else cout << "OAQ\n";
}