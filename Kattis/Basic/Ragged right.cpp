// 注意題目 是除了最後一行
#include<bits/stdc++.h>
using namespace std;

int main()
{
	int l,max=0,ls[80],i=0,sum=0;
	string s;
	while(getline(cin,s))
	{
		l = s.length();
		if(l > max) max = l;
		ls[i] = l;
		i++;
	}
	for(int j=0;j<i-1;j++)
	{
		sum += pow(max - ls[j],2);
	}
	cout << sum << "\n";
}