#include <bits/stdc++.h>
#define int long long
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0)

signed main()
{
	ShiYu;
	int t;cin >> t;
	while(t--)
	{
		int n;cin >> n;
		int a[n],sum=0;
		// 計算sum 直接絕對值加總
		for(int i=0;i<n;i++)
		{
			cin >> a[i];
			sum += abs(a[i]);
		}
		// 計算step 讓所有數都變正數所需步驟
		bool p = 0; //判斷是全為正數
		int i,l,r,step=0;
		while(p == 0)
		{
			bool f = 0;
			p = 1;
			//找邊界l,r
			for(i=0;i<n;i++)
			{
				if(a[i] < 0)
				{
					if(f == 0)
					{
						l = i;
						r = i;
						f = 1;
					}
					else r = i;
				}
			}
			// l,r 範圍內全部變號
			for(i=l;i<=r;i++) a[i] *= -1;
			step++;
			// 判斷是否全為正數 否則再跑一次
			for(i=0;i<n;i++)
			{
				if(a[i] < 0)
				{
					p = 0;
					break;
				}
			}
		}
		cout << sum << ' ' << step << "\n";
	}
}