#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long n,q; cin >> n >> q;
	int g[1000]={0},cmd,x,y;
	bool ans;
	while(q--)
	{
		cin >> cmd >> x >> y;
		if(cmd == 0)
		{
			ans = true;
			for(int i=x-1;i<y;++i)
			{
				if(g[i] == 0)
				{
					ans = false;
					break;
				}
			}
			if(ans) cout << "YES\n";
			else cout << "NO\n";
		}
		else
		{
			for(int i=x-1;i<y;++i)
			{
				if(g[i] == 0) g[i] = 1;
			}
			for(int i=0;i<n;++i) cout << g[i] << ' ';
			cout << "\n";
		}
	}
}