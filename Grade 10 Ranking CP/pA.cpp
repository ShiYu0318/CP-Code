#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long n,c; cin >> n >> c;
	long long p=0,s=0,t,a,sum=0;
	bool ans = false;
	while(n--)
	{
		cin >> t >> a;
		while(s!=t)
		{
			if(s+1 == t) p += a;
			sum += p;
			s++;
			// cout << s << ' ' << p << ' ' << sum << '\n';
			if(sum >= c)
			{
				ans = true;
				break;
			}
		}
		if(ans) break;
	}
	if(ans) cout << s << '\n';
	else
	{
		while(sum < c)
		{
			sum += p;
			s++;
		}
		cout << s << '\n';
	}
}