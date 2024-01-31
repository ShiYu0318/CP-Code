#include <iostream>
using namespace std;
#define ios_base ::sync_with_stdio(0);cin.tie(0);cout,tie(0);

int main()
{
	int Z,I,L,M,c=1,r=1;
	while(cin >> Z >> I >> M >> L)
	{
		if (Z + I + M + L == 0) break;
		int a[M];
		for(int i = 0;i < M;i++) a[i] = 0;
		while(!a[L])
		{
			a[L] = r;
			L = (Z * L + I) % M;
			r++;
		}
		cout << "Case " << c++ << ": " << r - a[L] << "\n";
	}
}