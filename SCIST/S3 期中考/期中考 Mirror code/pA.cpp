#include <iostream>
using namespace std;

int same(string s1,string s2,int l,int r)
{
	for (int j = l - 1;j < r;j++)
	{
		if (s1[j] == s2[j]) continue;
		else
		{
			cout << "I am so weak.\n";
			return 0;
		}
	}
	cout << "Really?!\n";
	return 0;
}

int main()
{
	string s1,s2;
	int q,l,r;
	cin >> s1 >> s2 >> q;
	for (int i = 0;i < q;i++)
	{
		cin >> l >> r;
		same(s1,s2,l,r);
	}
}