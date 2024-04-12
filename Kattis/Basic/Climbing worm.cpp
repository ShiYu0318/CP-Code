#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a,b,h,n=0,ans=0;
	cin >> a >> b >> h;
	while(1)
	{
		n += a;
		ans++;
		if(n >= h) break;
		n -= b;
	}
	cout << ans << "\n";
}