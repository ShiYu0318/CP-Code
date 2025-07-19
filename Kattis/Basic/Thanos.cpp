#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long t,p,r,f,ans;
	cin >> t;
	while(t--)
	{
		ans = 0;
		cin >> p >> r >> f;
		while(p <= f)
		{
			ans++;
			p *= r;
		}
		cout << ans << '\n';
	}
}