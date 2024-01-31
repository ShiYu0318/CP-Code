#include <bits/stdc++.h>
using namespace std;
// 注意二維陣列大小有沒有開相反
signed main()
{
	string a,b; cin >> a >> b;
	int n = a.size(), m = b.size(),x,y;
	bool find = false;
	
	for(int i=0;i<n;++i)
	{
		for(int j=0;j<m;++j)
		{
			if(a[i] == b[j])
			{
				x = i;
				y = j;
				find = true;
				break;
			}
		}
		if(find) break;
	}
	
	for(int i=0;i<m;++i)
	{
		for(int j=0;j<n;++j)
		{
			if(i == y) cout << a[j];
			else if(j == x) cout << b[i];
			else cout << '.';
		}
		cout << "\n";
	}
}