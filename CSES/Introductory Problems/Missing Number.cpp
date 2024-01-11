#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0);cin.tie(0)
#define int long long
#define input(x) for(auto &i : x) cin >> i; 
#define all(x) x.begin(),x.end()

signed main()
{
	ShiYu;
	int n; cin >> n;
	vector<int> v(n); input(v);
	sort(all(v));
	int i;
	for(i=0;i<n;++i)
	{
		if(a[i] != i+1) break;
	}
	cout << i+1 << "\n";
}