#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a,b,x=0,y=0;
	cin >> a >> b;
	if(a % 2 == 0) x++;
	if(b % 2 == 0) x++;
	if(a % 3 == 0) y++;
	if(b % 3 == 0) y++;
	cout << x << " " << y << "\n";
}