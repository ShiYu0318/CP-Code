#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
 
int main()
{
	ll t;
	cin >>t;
	while(t--)
	{
		ll n,k,x;
		cin>>n>>k>>x;
		ll sum = (k*(k+1))/2;
		ll sum2 = n * (n+1)/2 - (n-k) * (n-k+1)/2;
		
		
		if (sum==x)
		{
			cout<<"YES\n";
 
		}
		else if (sum2>=x && sum<x)
		{
			cout<<"YES\n";
		}
		else
		{
			cout<<"NO\n";
		}
 
	}
 
}