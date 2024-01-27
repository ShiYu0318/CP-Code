#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	if(n < 60) cout << "F\n";
	else if(n < 70) cout << "D\n";
	else if(n < 80) cout << "C\n";
	else if(n < 90) cout << "B\n";
	else if(n < 100) cout << "A\n";
	else cout << "S\n";
}