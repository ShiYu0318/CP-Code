#include <bits/stdc++.h>
using namespace std;

signed main()
{
	int n,w,h; cin >> n >> w >> h;
	int t,l = sqrt(pow(w,2) + pow(h,2));
	while(n--)
	{
		cin >> t;
		if(t <= l) cout << "DA\n";
		else cout << "NE\n";
	}
}