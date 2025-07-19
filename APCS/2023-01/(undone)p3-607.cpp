#include <bits/stdc++.h>
using namespace std;

string plus_num(string s,int a)
{
	char n[s.size()-2];
	for(int i=0;i<s.size();i++)
	{
		if(i+1 == a)
		{
			n[i] = s[i] + s[i+2];
			i += 2;
		}
		else n[i] = s[i];
	}
	string t = n;
	return t;
}

int main()
{
	int i;
	//long long ans;
	string s;
	cin >> s;
	while(1)
	{
		for(i=0;i<s.size();i++)
		{
			if(s[i] == '+')
			{
				s = plus_num(s,i);
			}
		}
		break;
	}
	cout << s;
}