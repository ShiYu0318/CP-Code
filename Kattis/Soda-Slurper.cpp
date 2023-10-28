#include<bits/stdc++.h>
using namespace std;

int main()
{
	int e,f,c,n,ans=0;
	cin >> e >> f >> c;
	n = e + f;
	while(n >= c)
	{
		ans += n / c;
		n = (n / c) + (n % c);
	}
	cout << ans << "\n";
}