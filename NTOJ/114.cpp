#include <bits/stdc++.h>
using namespace std;

signed main()
{
	int tb[5][6],i,j,same=0;
	bool ans = false;
	for(i=0;i<5;++i){
		for(j=0;j<6;++j) cin >> tb[i][j];
	}
	
	for(i=0;i<5;++i)
	{
		for(j=1;j<6;++j)
		{
			if(tb[i][j] == tb[i][j-1])
			{
				same++;
				if(same == 2)
				{
					ans = true;
					break;
				}
			}
			else same = 0;
		}
		if(ans == true) break;
		same = 0;
	}
	
	if(ans == true) cout << "Yes\n";
	else //cout << "No\n";
	{
		same = 0;
		for(i=0;i<6;++i)
		{
			for(j=1;j<5;++j)
			{
				if(tb[j][i] == tb[j-1][i])
				{
					same++;
					if(same == 2)
					{
						ans = true;
						break;
					}
				}
				else same = 0;
			}
			if(ans == true) break;
			same = 0;
		}
		
		if(ans == true) cout << "Yes\n";
		else cout << "No\n";	
	}
	return 0;
}