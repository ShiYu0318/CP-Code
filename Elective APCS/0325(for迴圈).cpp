#include <bits/stdc++.h>
using namespace std;
/*
3/25 113 29 黃士育
1. 輸出 1 到 10
2. 等差級數和
3. 等差級數平方和
4. 輸出 10 到 1
*/
int main()
{
	int i;
	for(i=1;i<=10;i++) cout << i << ' ';
	cout << '\n';
	
	int a,b,sum=0;
	cin >> a >> b;
	for(i=a;i<=b;i++) sum += i;
	cout << a << "+ ... +" << b << " = " << sum << "\n";
	
	sum = 0;
	for(i=a;i<=b;i++) sum += pow(i,2);
	cout << a << "^2+ ... +" << b << "^2 = " << sum;
	
	for(i=10;i<=1;i--) cout << i << ' ';
}