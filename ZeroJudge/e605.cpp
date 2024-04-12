#include <bits/stdc++.h>
using namespace std;
// NA score:50% 原因:(0 < n, m ≤ 100) 但要開tb[102][102]才會對
signed main()
{
	int n,m,i,j,c=1;
	while(cin >> n >> m)
	{
		if(n == 0 && m == 0) break;
		else
		{
			char ip[n][m];
			for(i=0;i<n;++i) for(j=0;j<m;++j) cin >> ip[i][j];
			int tb[102][102] = {},x,y;
			for(i=0;i<n;++i) for(j=0;j<m;++j) if(ip[i][j] == '*')
			{
				x = i+1; y = j+1;
				tb[x-1][y-1]++;
				tb[x-1][y]++;
				tb[x-1][y+1]++;
				
				tb[x][y-1]++;
				tb[x][y+1]++;
				
				tb[x+1][y-1]++;
				tb[x+1][y]++;
				tb[x+1][y+1]++;
			}
			
			cout << "Field #" << c << ":\n";
			c++;
			for(i=1;i<=n;++i)
			{
				for(j=1;j<=m;++j)
				{
					if(ip[i-1][j-1] == '*') cout << '*';
					else cout << tb[i][j];
				}
				cout << '\n';
			}
		}
		cout << '\n';
	}
	return 0;
}