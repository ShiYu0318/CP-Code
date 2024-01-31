#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s,words[80];
	int n=0,l=0,r=0;
	getline(cin,s);
	for(int i=0;i<s.size();i++)
	{
		if(s[i] == ' ' || i == s.size()-1)
		{
			r = i;
			if(i == s.size()-1) r = i+1;
			for(int j=0;j<n;j++)
			{
				if(s.substr(l,r-l) == words[j])
				{
					cout << "no\n";
					return 0;
				}
			}
			words[n] =  s.substr(l,r-l);
			l = i+1;
			n++;
		}
	}
	cout << "yes\n";
}