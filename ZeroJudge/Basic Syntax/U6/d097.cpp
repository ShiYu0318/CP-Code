#include<bits/stdc++.h>
using namespace std;
#define input(x) for(auto &i : x) cin >> i
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define RPT(i,n) FOR(i,0,n)
#define all(x) x.begin(),x.end()

int main()
{
	int n;
	while(cin >> n)
	{
		vector<int> v(n); input(v);
		vector<int> d(n-1);
		RPT(i,n-1)
		{
			d[i] = abs(v[i+1] - v[i]);
		}
		sort(all(d));
		bool ans = true;
		FOR(i,1,n)
		{
			if(d[i-1] != i)
			{
				ans = false;
				break;
			}
		}
		cout << (ans ? "Jolly" : "Not jolly") << "\n"; 
	}
}