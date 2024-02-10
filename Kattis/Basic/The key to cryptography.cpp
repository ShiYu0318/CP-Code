#include<bits/stdc++.h>
using namespace std;

signed main()
{
	string c,k,m,t;cin >> c >> k;
	for(int i=0;i<c.size();++i)
	{
		if((c[i] - (k[i] - 'A')) < 'A')
		{
			t = (char)('Z' - ((k[i] - 'A') - (c[i] - 'A'))+1);
		}
		else t = (char)(c[i] - (k[i] - 'A'));
		m += t;
		k += t;
	}
	cout << m << "\n";
}