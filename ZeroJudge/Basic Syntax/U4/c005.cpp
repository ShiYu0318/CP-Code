#include <iostream>
using namespace std;
#define ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

int main()
{
	long long n,f,a,b,c,ans;
	cin >> n;
	for (int i = 0;i < n;i++)
	{
		cin >> f;
		ans = 0;
		for (int j = 0;j < f;j++)
		{
			cin >> a >> b >> c;
			ans += a * c;
		}
		cout << ans << "\n";
	}
}