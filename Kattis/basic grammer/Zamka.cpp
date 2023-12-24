#include<bits/stdc++.h>
using namespace std;

int main()
{
	int l,d,x,n,m,s,t;
	cin >> l >> d >> x;
	for(int i=l;i<=d;i++)
	{
		t = i;
		s = 0;
		while(t!=0)
		{
			s += t % 10;
			t /= 10;
		}
		if(s == x)
		{
			n = i;
			break;
		}
	}
	cout << n << "\n";
	
	for(int i=d;i>=0;i--)
	{
		t = i;
		s = 0;
		while(t!=0)
		{
			s += t % 10;
			t /= 10;
		}
		if(s == x)
		{
			m = i;
			break;
		}
	}
	cout << m << "\n";
}
