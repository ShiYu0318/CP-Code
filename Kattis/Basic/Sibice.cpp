#include <bits/stdc++.h>
using namespace std;

signed main()
{
	int n,w,h; cin >> n >> w >> h;
	int t,l = sqrt(w*w + h*h);
	while(n--)
	{
		cin >> t;
		if(t <= l) cout << "DA\n";
		else cout << "NE\n";
	}
}