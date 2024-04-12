#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long n,m; cin >> n >> m;
	long fav[m],sub[n],dif[n];
	for(int i=0;i<m;++i) cin >> fav[i];
	for(int i=0;i<n;++i) cin >> sub[i];
	for(int i=0;i<n;++i) cin >> dif[i];
	int c[n],ans=0;
	bool h;
	for(int i=0;i<n;++i)
	{
		h = false;
		for(int j=0;j<ans;++j)
		{
			if(dif[i] == c[j])
			{
				h = true;
				break;
			}
		}
		//cout << '\n';
		if(!h)
		{
			ans++;
			c[ans-1] = dif[i];
		}
		//for(int j=0;j<ans;++j) cout << c[j] << ' ';
		//cout << '\n';
	}
	cout << ans << "\n";
}