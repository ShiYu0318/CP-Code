#include <bits/stdc++.h>
using namespace std;
/*
3/27
113 29 黃士育 
等差級數和
等差級數平方和
*/
int main()
{
	int i,a1,an,d,sum=0;
	cin >> a1 >> an >> d;
	for(i=a1;i<=an;i+=d) sum += i;
	cout << a1 << "+ ... +" << an << " = " << sum << "\n";
	
	cin >> a1 >> an >> d;
	for(i=a1;i<=an;i+=d) sum += pow(i,2);
	cout << a1 << "^2 + ... +" << an << "^2 = " << sum;
	
}