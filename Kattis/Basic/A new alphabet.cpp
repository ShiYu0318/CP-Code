#include<bits/stdc++.h>
using namespace std;
// 這題用建表的方法做 要注意裡面的元素有'\'跳脫字元的話 要在'\'符號前面再用一個'\'把他跳脫出來
signed main()
{
	string s,n[26] = {"@","8","(","|)","3","#","6","[-]","|","_|","|<","1","[]\\/[]",
					"[]\\[]","0","|D","(,)","|Z","$","']['","|_|","\\/","\\/\\/","}{","`/","2"};
	getline(cin,s);
	for(int i=0;i<s.size();i++)
	{
		if(s[i] >= 'A' && s[i] <= 'Z') cout << n[s[i] - 'A'];
		else if(s[i] >= 'a' && s[i] <= 'z') cout << n[s[i] - 'a'];
		else cout << s[i];
	}
	cout << "\n";
}