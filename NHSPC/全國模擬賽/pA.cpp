#include <bits/stdc++.h>
using namespace std;
#define FORn(i,n) for(int i=0;i<n;++i)
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define F first
#define S second
#define dbg(x) cout << #x << "=" << x << ' '
#define nl cout << "\n"

signed main()
{
	int n; cin >> n;
	vector<pair<int,int> > v(n);
	FORn(i,n)
	{
		cin >> v[i].F >> v[i].S;
	}
	int maxn = INT_MIN;
	FORn(i,n)
	{
		int sum = 0;
		// dbg(i);nl;
		FORn(j,n)
		{
			if((i == 0 && j == 0) || (i != 0 && j == i) || (i == n-1 && j == n-2)) continue;
			
			else if(i != 0 && j == i-1)
			{
				sum += v[j].F * v[i+1].S;
				sum -= v[j].S * v[i+1].F;
				dbg(j);dbg(v[j].F);dbg(v[i+1].S);nl;
			}
			else 
			{
				sum += v[j].F * v[j+1].S;
				sum -= v[j].S * v[j+1].F;
				dbg(j);dbg(v[j].F);dbg(v[j+1].S);nl;
			}
		}
		maxn = max(maxn,abs(sum));
	}
	cout << maxn * 2 << "\n";
}