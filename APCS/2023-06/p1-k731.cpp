#include <bits/stdc++.h>
using namespace std;

signed main()
{
	int n; cin >> n;
	int x,y,a,b;
	int ans[3] = {0};
	char p = 'E';
	cin >> a >> b;
	n--;
	while(n--)
	{
		cin >> x >> y;
		if(x == a)
		{
			if(y > b)
			{
				if(p == 'E') ans[0]++;
				else if(p == 'W') ans[1]++;
				else if(p == 'S') ans[2]++;
				p = 'N';
			}
			else
			{
				if(p == 'W') ans[0]++;
				else if(p == 'E') ans[1]++;
				else if(p == 'N') ans[2]++;
				p = 'S';
			}
		}
		else
		{
			if(x > a)
			{
				if(p == 'S') ans[0]++;
				else if(p == 'N') ans[1]++;
				else if(p == 'W') ans[2]++;
				p = 'E';
			}
			else
			{
				if(p == 'N') ans[0]++;
				else if(p == 'S') ans[1]++;
				else if(p == 'E') ans[2]++;
				p = 'W';
			}
		}
		a = x;
		b = y;
	}
	cout << ans[0] << ' ' << ans[1] << ' ' << ans[2] << "\n";
}