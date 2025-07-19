#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t,n;
	string s;
	cin >> t;
	while(t--)
	{
		cin >> n >> s;
		int a = 1;
		for(int j=0;j<n;j++)
		{
			for(int q=0;q<n;q++)
			{
				if(s[q] == s[j])
				{
					if(q%2 == j%2) continue;
					else
					{
						a = 0;
						break;
					}
				}
			}
			if(!a) break;
		}
		if(a) cout << "YES\n";
		else cout << "NO\n";
	}
}