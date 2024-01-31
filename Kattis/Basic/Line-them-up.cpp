#include<bits/stdc++.h>
#define int long long
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

signed main()
{
	IO;
	int n;
	string a,b;
	bool increasing=false,neither=false;
	cin >> n >> a >> b;
	if(a < b) increasing = true;
	for(int i=0;i<n-2;i++)
	{
		a = b;
		cin >> b;
		
		if(a > b && increasing) neither=true;
		else if(a < b && !increasing) neither=true;
		
		if(neither) break;
	}
	if(neither) cout << "NEITHER\n";
	else
	{
		if(increasing) cout << "INCREASING\n";
		else cout << "DECREASING\n";
	}
}