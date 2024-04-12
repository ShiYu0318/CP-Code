#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,i,d,p[100];
	cin >> n;
	p[0] = 1;
	for(i=2;i<=n;i++)
	{
		cin >> d;
		p[d+1] = i;
	}
	for(i=0;i<n;i++) cout << p[i] << ' ';
}