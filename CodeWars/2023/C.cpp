#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0)

signed main()
{
    ShiYu;
    int n; cin >> n;
    string ans = "",s;
    getline(cin,s);
    while(n--)
    {
    	getline(cin,s);
    	string t = "";
    	for(int i=0;i<(int)s.size();++i)
    	{
    		if((s[i] < 'A' || 'Z' < s[i]) && (s[i] < 'a' || 'z' < s[i]))
    		{
    			continue;
    		}
    		if('A' <= s[i] && s[i] <= 'Z')
    		{
    			t += s[i] + ('a' - 'A');
    			continue;
    		}
    		else
    		{
    			t += s[i];
    		}
    		
    	}
    	// cout << t << "\n";
    	if(t == "" || s == "")
    	{
    		ans += 'N';
    		continue;
    	}
    	
    	bool yn = true;
    	int i=0,j=t.size()-1;
    	while(i < j)
    	{
    		if(t[i] != t[j])
    		{
    			if(t[i+1] != t[j])
    			{
    				if(t[i] != t[j-1])
    				{
    					yn = false;
    					break;
    				}
    				else j--;	
    			}
    			else i++;
    		}
    		else
    		{
    			i++; 
    			j--;
    		}
    		
    	}
    	if(yn) ans += 'Y';
    	else ans += 'N';
    }
    cout << ans;
    return 0;
}