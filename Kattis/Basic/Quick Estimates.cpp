// 這題用int做的話 輸入0會比較難做 所以用string的長度來做
#include<bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	int n;
	cin >> n;
	while(n--)
	{
		cin >> s;
		cout << s.length() << "\n";
	}	
}