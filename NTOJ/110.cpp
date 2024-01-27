#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t,n,i,j;
	cin >> t;
	while(t--)
	{
		cin >> n;
		//   *
		//  ***
		// *****
		for(i=1;i<=n-3;i++) // 行數
		{
			for(j=n-i;j>0;j--) cout << " ";
			for(j=0;j<2*i-1;j++) cout << "*";
			cout << "\n";
		}
		
		// ***********
		//  *********
		// ***********
		for(i=0;i<2*n-1;i++) cout << "*";
		cout << "\n";
		cout << " ";
		for(i=0;i<2*n-3;i++) cout << "*";
		cout << "\n";
		for(i=0;i<2*n-1;i++) cout << "*";
		cout << "\n";
		
		// *****
		//  ***
		//   *
		for(i=n-3;i>0;i--)
		{
			for(j=0;j<(n-i);j++) cout << " ";
			for(j=0;j<2*i-1;j++) cout << "*";
			cout << "\n";
		}
		
		
	}
}