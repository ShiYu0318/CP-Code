#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,k,i,j,h,b=1,c=0;
	cin >> n >> k;
	for(i=0;i<n*k;i++)// 有幾行
	{

		for(j=0;j<n;j++)//每行有幾塊地板
		{
			for(h=0;h<k;h++)// 每塊地板有幾個格
			{
				if(b==1) cout << "*";
				else if(b==0) cout << " ";
			}
			if(b==1) b--;
			else if(b==0) b++;
		}
		c++;
		if((n%2==0 && c==k)||(n%2!=0 && c!=k))
		{
			if(b==1) b--;
			else if(b==0) b++;
		}
		if(c==k) c = 0;
		cout << "\n";
	}
}