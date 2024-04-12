#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	int hide=0,j=0;
	getline(cin,s);
	string n = s;
	for(int i=0;i<s.size();i++)
	{
		if(hide != 0)
		{
			hide--;
			continue;
		}
		// 判斷是否為母音 是的話隱藏母音後的p
		bool vowel = (s[i] == 'a') || (s[i] == 'e') || (s[i] == 'i') || (s[i] == 'o') || (s[i] == 'u');
		if(vowel)
		{
			hide++;
			// 當母音下一個的p被隱藏後 判斷p下一個是否為母音 是的話再隱藏一個
			bool vowel = (s[i+2] == 'a') || (s[i+2] == 'e') || (s[i+2] == 'i') || (s[i+2] == 'o') || (s[i+2] == 'u');
			if(vowel)
			{
				hide++;
			}
		}
		n[j] = s[i];
		j++;
	}
	for(int i=0;i<j;i++) cout << n[i];
	cout << '\n';
}