#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
    int n,m,k,q,key,x,y,k1,k2,k3,x1,y1,x2,y2,x3,y3,x4,y4,ans=1;
    cin >> n >> m >> k >> q;
    vector<int> b;
    while(k--)
    {
        cin >> key >> x >> y;
        b.push_back(key);
        b.push_back(x);
        b.push_back(y);
    }
    while(q--)
    {
        cin >> k1 >> k2 >> k3;
        x1 = b[3 * k1 - 2];
        y1 = b[3 * k1 - 1];
        x2 = b[3 * k2 - 2];
        y2 = b[3 * k2 - 1];
        x3 = b[3 * k3 - 2];
        y3 = b[3 * k3 - 1];
        // cout << x1 << " " << y1 << '\n' << x2 << " " << y2 << '\n' << x3 << " " << y3 << '\n';
        ans = 1;
        if(x1 == x2)
        {
        	if(y3 == y1)
        	{
        		x4 = x3;
        		y4 = y2;
        	}
        	else if(y3 == y2)
        	{
        		x4 = x3;
        		y4 = y1;
        	}else ans = 0;
        }
        else if(x1 == x3)
        {
        	if(y2 == y1)
        	{
        		x4 = x2;
        		y4 = y3;
        	}
        	else if(y2 == y3)
        	{
        		x4 = x2;
        		y4 = y1;
        	}else ans = 0;
        }
        else if(x2 == x3)
        {
        	if(y1 == y2)
        	{
        		x4 = x1;
        		y4 = y3;
        	}
        	else if(y1 == y3)
        	{
        		x4 = x1;
        		y4 = y2;
        	}else ans = 0;
        }
        else ans = 0;
        
        if(ans==1)
        {
            for(int i=0;i<n;i++)
            {
                if(b[i]==x4 && b[i+1]==y4)
                {
                    cout << "Find ghost key: " << b[i-1] << '\n';
                }
        	}
        }else cout << "Not ghost key condition!\n";
    }
	return 0;
}