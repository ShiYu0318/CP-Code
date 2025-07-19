#include <bits/stdc++.h>
using namespace std;

int main()
{
	int p,q,r;
	cin >> p >> q >> r;
	if(p > q && p > r)
	{
		if(q + r > p) cout << "yes\n";
		else cout << "no\n";
	}
	else if(q > p && q > r)
	{
		if(p + r > q) cout << "yes\n";
		else cout << "no\n";
	}
	else
	{
		if(p + q > r) cout << "yes\n";
		else cout << "no\n";
	}
}