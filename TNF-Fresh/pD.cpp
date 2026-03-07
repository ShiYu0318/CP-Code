#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int len,n; cin >> len >> n;
	int fl[len],t,l,r,c,x;
	for(int i=0;i<len;++i) fl[i] = 1;
	while(n--)
	{
		cin >> t;
		if(t == 1)
		{
			cin >> l >> r >> c;
			for(int i=l-1;i<r;++i) fl[i] = c;
		}
		else
		{
			cin >> x >> c;
			if(fl[x-1] != c) cout << "Yes\n";
			else cout << "NO\n";
		}
	}
}