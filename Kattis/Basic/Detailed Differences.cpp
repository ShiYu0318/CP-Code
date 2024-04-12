#include <bits/stdc++.h>
using namespace std;

int main()
{
	string a,b;
	int n,i;
	cin >> n;
	while(n--)
	{
		cin >> a >> b;
		string c = "";
		for(i=0;i<a.size();i++)
		{
			if(a[i] != b[i]) c += "*";
			else c += ".";
		}
		cout << a << "\n" << b << "\n" << c << "\n\n";
	}
}