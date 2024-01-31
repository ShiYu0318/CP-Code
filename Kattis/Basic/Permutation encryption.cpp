#include<bits/stdc++.h>
using namespace std;

signed main()
{
	int n;
	while(cin >> n)
	{
		if(n == 0) break;
		int k[n];
		for(int i=0;i<n;i++) cin >> k[i];
		string s;
		getline(cin,s);
		getline(cin,s);
		string tmp,c="'";
		int len=s.size(),t = len/n;
		if(len % n != 0)
		{
			t++;
			s.resize(len+(n-(len%n)),' ');
		}
		for(int i=0;i<t;i++)
		{
			tmp = s.substr(i*n,n);
			for(int j=0;j<n;j++) c += tmp[k[j]-1];
		}
		cout << c << "'\n";
	}
	return 0;
}