// unresolved
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	if(n==1) cout << 1 << '\n';	
	else
	{
		int s[n],m=1;
		for(int i=0;i<n;i++) cin >> s[i];
		while(1)
		{
			bool diff = true;			
			int tmp[n];	
			for(int i=0;i<n;i++)
			{
				tmp[i] = s[i] % m;
				for(int j=0;j<i;j++)
				{
					if(tmp[i] == tmp[j])
					{
						diff = false;
						break;
					}
				}
				if(!diff) break;
			}
			if(diff) break;
			m++;
		}
		cout << m << '\n';
	}
	return 0;
}