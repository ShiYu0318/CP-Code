#include <bits/stdc++.h>
using namespace std;

signed main()
{
	bool ans = true;
	int n; cin >> n;
	char cb[n][n];
	int i,j;
	for(i=0;i<n;++i) for(j=0;j<n;++j) cin >> cb[i][j];
	int b,w,same;
	for(i=0;i<n;++i)
	{
		b=0; w=0; same=0;
		for(j=0;j<n;++j)
		{
			if(cb[i][j] == 'B') b++;
			else w++;
			
			if(j != 0)
			{
				if(cb[i][j] == cb[i][j-1]) same++;
				else same = 0;
			}
			if(same == 2)
			{
				ans = false;
				break;
			}
		}
		if(!ans) break;
		else same = 0;
		
		if(b == w) continue;
		else
		{
			ans = false;
			break;
		}
	}
	if(ans)
	{
		for(i=0;i<n;++i)
		{
			b=0; w=0; same=0;
			for(j=0;j<n;++j)
			{
				if(cb[j][i] == 'B') b++;
				else w++;
				
				if(i != 0)
				{
					if(cb[j][i] == cb[j-1][i]) same++;
					else same = 0;
				}
				if(same == 2)
				{
					ans = false;
					break;
				}
			}
			if(!ans) break;
			else same = 0;
			
			if(b == w) continue;
			else
			{
				ans = false;
				break;
			}
		}
	}
	if(ans) cout << 1 << "\n";
	else cout << 0 << "\n";
}