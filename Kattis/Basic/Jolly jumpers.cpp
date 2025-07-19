#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	while(cin >> n)
	{
		long long i,l=0,a,b;
		bool jolly = true;
		int d[3000]={0},t[3000]={0};
		cin >> a;
		for(i=0;i<n-1;i++) 
		{
			cin >> b;
			d[i] = abs(b - a);
			if(d[i] > l) l = d[i];
			a = b;
			t[d[i]] = 1;
		}
		for(i=1;i<=n-1;i++)
		{
			if(t[i] != 1)
			{
				jolly = false;
				break;
			}
		}
		if(jolly == true) cout << "Jolly\n";
		else cout << "Not jolly\n";
	}
}