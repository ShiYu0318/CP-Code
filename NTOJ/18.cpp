#include<bits/stdc++.h>
using namespace std;
// 思路：先篩選英文字母都變成小寫存進新的字串 再用迴圈判斷新的字串是否回文
// 注意子母 大小寫也算相同
signed main()
{
	string s;
	bool ans;
	int len;
	while(getline(cin,s))
	{
		ans = true;
		string ns;
		for(int i=0;i<s.size();i++)
		{
			if(s[i] >= 'A' && s[i] <= 'Z') ns += s[i] + ('a'-'A');
			else if(s[i] >= 'a' && s[i] <= 'z') ns += s[i];
		}
		len = ns.size();
		// cout << len << " " << ns << "\n";
		for(int i=0;i<=len/2;i++)
		{
			if(ns[i] != ns[len-i-1])
			{
				ans = false;
				break;
			}
		}
		if(ans) cout << "SETUP! " + s + "\n";
		else cout << s << "\n";
	}
}