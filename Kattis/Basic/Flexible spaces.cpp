#include <bits/stdc++.h>
using namespace std;

int main()
{
	// 宣告＆輸入
	int w,p,i,sum;
	cin >> w >> p;
	int ip[p],d[p+1],c[100]={0};
	for(i=0;i<p;i++) cin >> ip[i];
	// 算出間隔距離存入陣列d
	d[0] = ip[0];
	for(i=1;i<p;i++) d[i] = ip[i] - ip[i-1];
	d[p] = w - ip[p-1];
	// 排列組合出所有可能性並建表紀錄結果
	for(i=1;i<=p+1;i++)
	{
		for(int j=0;j<p+1-i+1;j++)
		{
			sum = 0;
			for(int k=j;k<j+i;k++) sum += d[k];
			c[sum] = 1;
		}
	}
	// 檢查表中結果並輸出
	for(i=0;i<=w;i++)
	{
		if(c[i] == 1) cout << i << ' ';
	}
	cout << '\n';
}