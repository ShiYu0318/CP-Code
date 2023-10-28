#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define FOR(i,n) for(int i=0;i<n;++i)

signed main()
{
    ShiYu
    vector<double> v;
    string s;
    while(cin >> s)
    {
    	bool c = true;
    	FOR(i,s.size())
    	{
    		// 過濾Ee以外字母
    		if(('A' <= s[i] && s[i] <= 'Z' && s[i] != 'E') || ('a' <= s[i] && s[i] <= 'z' && s[i] != 'e'))
    		c = false;
    		break;
    		// e 後面沒東西
    		if(('A' <= s[i] && s[i] <= 'Z' && s[i] == 'E') || ('a' <= s[i] && s[i] <= 'z' && s[i] == 'e'))
    		{
    			if(i == s.size()-1)
    			{
    				c = false;
    				break;
    			}
    			bool k = true;
    			for(int j=i;j<s.size();++j)
    			{
    				if(s[j] == '.')
    				{
    					k = false;
    					break;
    				}
    			}
    			if(!k)
    			{
    				c = false;
    				break;
    			}
    		}
    		if(s[i] == '-' || s[i] == '+' )
    		{
    			if(s[i+1] == '-' || s[i+1] == '+')
    			{
    				c = false;
    				break;
    			}
    		}
    	}

    }
	// 後面時間到了沒寫完
    return 0;
}