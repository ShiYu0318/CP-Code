#include <bits/stdc++.h>
#define int long long
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0)
using namespace std;

signed main()
{
	IO;
	int n;
	cin >> n;
	string s;
	getline(cin,s); // 這行getline用來吃掉cin >> n後的換行符 避免迴圈裡的第一次getline只讀到空白
	while(n--)
	{
		getline(cin,s);
		if(s.substr(0,11) == "Simon says ")
		{
			cout << s.substr(11) << "\n";
		}
	}
}