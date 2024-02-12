#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t,a,b,sum=0;
	cin >> t;
	if(t % 2 != 0) cout << "still running\n";
	else
	{
		t /= 2;
		while(t--)
		{
			cin >> a >> b;
			sum += b - a;
		}
		cout << sum << "\n";
	}
}