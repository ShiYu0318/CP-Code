#include<iostream>
using namespace std;

int main()
{
    string s;
	int t,n,q=0,m[4] = {'m','e','o','w'};
	cin >> t;
	for(int i=0;i<t;i++)
	{
		cin >> n >> s;
		q = 0;
		// 大寫轉小寫
	    for(int i = 0;i<n;i++)
	    {
	        if(s[i]>='A' && s[i]<='Z')
	        {
	            s[i] = s[i] + 32;
	        }
	    }
	    for(int i=0;i<n;i++)
	    {
	    	if(s[i] == m[q])
	    	{
	    		continue;
	    	}
	    	else
	    	{
	    		q++;
	    		if(s[i] == m[q])
	    		{
	    			continue;
	    		}
	    		else
	    		{
	    			cout << "NO\n";
	    			break;
	    		}
	    	}
	    }
	    if(q == 3)
	    {
	    	cout << "YES\n";
	    }
    }
}