#include<bits/stdc++.h>
using namespace std;

signed main()
{
	int t;cin >> t;
	while(t--)
	{
		int n;cin >> n;
		int a[n];
		for(int i=0;i<n;i++) cin >> a[i];
		int len = sizeof(a) / sizeof(int);
		sort(a,a+len);
		int sum=0;
		for(int i=0;i<len/2;i++) sum += a[len-i-1] - a[i];
		cout << sum << "\n";
	}
}