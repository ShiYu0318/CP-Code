#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t,n1,n2,i;
	cin >> t;
	while(t--)
	{
		float sum1=0,sum2=0,ans=0,ave1,ave2,c1,c2;
		cin >> n1 >> n2;
		int iq1[n1],iq2[n2];
		for(i=0;i<n1;i++)
		{
			cin >> iq1[i];
			sum1 += iq1[i];
		}
		ave1 = sum1 / n1;
		
		for(i=0;i<n2;i++)
		{
			cin >> iq2[i];
			sum2 += iq2[i];
		}
		ave2 = sum2 / n2;

		for(i=0;i<n1;i++)
		{
			c1 = (sum1 - iq1[i])/(n1-1);
			c2 = (sum2 + iq1[i])/(n2+1);
			if(c1 > ave1 && c2 > ave2) ans++;
		}
		cout << ans << "\n";
	}
}