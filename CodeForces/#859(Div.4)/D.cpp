#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t,n,q,l,r,k,a[200000] = {0};
	cin >> t;
	for(int i=0;i<t;i++)
	{
		cin >> n >> q;
		for(int j=0;j<n;j++) cin >> a[j];
		for(int j=0;j<q;j++)
		{
			int s=0,b[n];
			for(int c=0;c<n;c++) b[c] = a[c];
			cin >> l >> r >> k;
			for(int h=l-1;h<r;h++) b[h] = k;
			for(int j=0;j<n;j++) cout << b[j] << ' ';
			for(int g=0;g<n;g++) s += b[g];
			cout << '\n' << s << '\n';
			if(s%2 == 1) cout << "YES\n";
			else cout << "NO\n";
		}
	}
}