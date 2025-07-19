#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,p,x,y; cin >> n >> p >> x >> y;
    int m = 0,ans = 0,i = 0;
    while(1)
    {
        i++;
        if(i % n == 0)
        {
            ans += y;
            continue;
        }
        m++;
        ans += x;
        if(m == p)
        {
            if((i + 1) % n == 0) ans += y;
            break;
        }
    }
    cout << ans << '\n';
}