#include<bits/stdc++.h>
#define int long long
#define IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

signed main()
{
	IO;
	char c[7]={'A','B','C','D','E','F','G'},p,q;
	int d[6]={3,1,4,1,5,9},a,b,ans=0;
	cin >> p >> q;
	for(int i=0;i<7;i++)
	{
		if(c[i] == p) a = i;
		if(c[i] == q) b = i;
	}
	if(a > b) swap(a,b);
	for(int i=a;i<b;i++) ans += d[i];
	cout << ans << "\n";
}