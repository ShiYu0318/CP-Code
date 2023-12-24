#include<bits/stdc++.h>
using namespace std;

int main()
{
	int sumA=0,sumB=0;
	string s;
	cin >> s;
	for(int i=0;i<s.size()/2;i++)// cout << s[i] << " ";
	{
		if(s[2*i] == 'A')
		{
			if(s[2*i+1] == '1') sumA += 1;
			else if(s[2*i+1] == '2') sumA += 2;
		}
		else if(s[2*i] == 'B')
		{
			if(s[2*i+1] == '1') sumB += 1;
			else if(s[2*i+1] == '2') sumB += 2;
		}
	}
	if(sumA > sumB) cout << "A\n";
	else if(sumA < sumB) cout << "B\n";
}