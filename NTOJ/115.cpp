#include <bits/stdc++.h>
using namespace std;

int main()
{
	string c[10],s;
	for(int i=0;i<10;i++) c[i] = "EMPTY";
	int n,p;
	cin >> n;
	while(n--)
	{
		cin >> s >> p;
		c[p-1] = s;
	}
	for(int i=0;i<10;i++) cout << c[i] << '\n';
}