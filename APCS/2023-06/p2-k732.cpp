#include <bits/stdc++.h>
using namespace std;
#define FOR(i,n) for(int i=0;i<n;++i)

signed main()
{
	int n,m; cin >> n >> m;
	int A[n][m]; FOR(i,n) FOR(j,m) cin >> A[i][j];
	vector< pair<int,int> > v;
	FOR(a,n) 
	{
		FOR(b,m)
		{
			int sum = 0;
			
			FOR(c,n)
			{
				
				FOR(d,m)
				{
					int t = abs(a-c)+abs(b-d);
					if(t <= A[a][b])
					{
						sum += A[c][d];
					}
				}
			}
			if(sum % 10 == A[a][b])
			{
				v.push_back(make_pair(a,b));
			}
		}
	}
	if(!v.empty())
	{
		cout << v.size() << '\n';
		FOR(i,v.size()) cout << v[i].first << ' ' << v[i].second << "\n";
	}
}