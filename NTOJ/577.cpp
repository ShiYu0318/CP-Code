#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long t,a,b;
	cin >> t;
	while(t--)
	{
		cin >> a >> b;
		long long ans = a;
		if(b == 0)
		{
			cout << 1 << "\n";
			continue;
		}
		for(int i=1;i<b;i++)
		{
			ans *= a;
		}
		cout << ans << "\n";
	}
}