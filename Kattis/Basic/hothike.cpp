#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,i,d,c,t=41;
	cin >> n;
	int a[n];
	for(i=0;i<n;i++) cin >> a[i];
	for(i=0;i<n-2;i++)
	{
		if(a[i] >= a[i+2]) c = a[i];
		else c = a[i+2];
		
		if(c < t)
		{
			d = i + 1;
			t = c;
		}
	}
	cout << d << ' ' << t << '\n';
}