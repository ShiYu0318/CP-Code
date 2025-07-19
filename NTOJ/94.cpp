#include <bits/stdc++.h>
using namespace std;

int main()
{
	int m;
	cin >> m;
	if(m == 3 || m == 4 || m == 5) cout << "Spring!\n";
	else if(m == 6 || m == 7 || m == 8) cout << "Summer!\n";
	else if(m == 9 || m == 10 || m == 11) cout << "Autumn!\n";
	else cout << "Winter!\n";
}