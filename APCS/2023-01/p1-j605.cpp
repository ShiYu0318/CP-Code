#include<bits/stdc++.h>
using namespace std;

int main()
{
	int k,t[10],s[10],max=-1,maxt=-1,e=0;
	cin >> k;
	for(int i=0;i<k;i++)
	{
		cin >> t[i] >> s[i];
		if(s[i] > max)
		{
			max = s[i];
			maxt = t[i];
		}
		if(s[i] == -1) e++;
	}
	int sum = max - k  - (e * 2);
	if(sum < 0) sum = 0;
	cout << sum << " " << maxt << "\n";
}