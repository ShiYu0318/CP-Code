#include <bits/stdc++.h>
using namespace std;

signed main()
{
	int t[13]={0},max=0;
	string c;
	while(cin>>c)
	{
		if('A' <= c[0] && c[0] <= 'Z')
		{
			if(c[0] == 'A') t[0]++;
			else if(c[0] == 'T') t[9]++;
			else if(c[0] == 'J') t[10]++;
			else if(c[0] == 'Q') t[11]++;
			else if(c[0] == 'K') t[12]++;
		}
		else t[c[0] - '0' - 1]++;
	}
	for(int i=0;i<13;i++)
	{
		if(t[i] > max) max = t[i];
	}
	cout << max << "\n";
}