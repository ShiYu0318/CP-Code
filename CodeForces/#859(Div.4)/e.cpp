#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t,n,a[20000];
	scanf("%d",t);
	for(int i=0;i<t;i++)
	{
		scanf("%d",n);
		for(int j=0;j<n;j++) scanf("%d",a[j]);
		printf("! %d\n",n/2);
	}
}