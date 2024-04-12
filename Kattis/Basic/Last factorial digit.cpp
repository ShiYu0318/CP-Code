#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t,n,ans;
	cin >> t;
	while(t--)
	{
		cin >> n;
		ans = 1;
		for(int i=2;i<=n;i++) ans *= i;
		cout << ans % 10 << "\n";
	}
}