// 這題測資不會過的原因是因為 要先把文本都轉換成小寫 再找出有沒有problem
#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	bool ans;
	while(getline(cin,s))
	{
		ans = false;
		for(int i=0;i<s.size();i++)
		{
			if(s[i] >= 'A' && s[i] <= 'Z') s[i] += 32;
		}
		for(int i=0;i<s.size();i++)
		{
			if(s.substr(i,7) == "problem")
			{
				ans = true;
				break;
			}
		}
		if(ans == true) cout << "yes\n";
		else cout << "no\n";
	}
}