#include <bits/stdc++.h>
using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,a,f,i,j,k;
	cin >> n;
	while(n--)
	{
		cin >> a >> f;
		for(i=0;i<f;i++)
		{
			for(j=1;j<=a;j++)
			{
				for(k=0;k<j;k++)
				{
					cout << j;
				}
				cout << '\n';
			}
			for(j=a-1;j>0;j--)
			{
				for(k=0;k<j;k++)
				{
					cout << j;
				}
				cout << '\n';
			}
			cout << '\n';
		}
	}
}