#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	if((a < c && c < b) || (a < d && d < b) || (c <= a && d >= b)) cout << "yes\n";
	else cout << "no\n";
}