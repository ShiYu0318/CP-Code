#include<bits/stdc++.h>
using namespace std;

int main()
{
	int k,q,r;
	cin >> k >> q >> r;
	string s;
	int p[k];
	char n[q][k];
	cin >> s;
	for(int i=0;i<q;i++)
	{
		for(int j=0;j<k;j++)
		{
			cin >> p[j];
			n[i][p[j]-1] = s[j];
		}
		s = n[i];
		// cout << s << "\n";
	}
	for(int i=0;i<r;i++)
	{
		for(int j=0;j<q;j++)
		{
			cout << n[j][i];
		}
		cout << "\n";
	}
}