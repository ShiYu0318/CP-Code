#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int w,h,n;; cin >> w >> h >> n;
    int x,y,t,a=0,b=w,c=0,d=h;
    while(n--)
    {
        cin >> x >> y >> t;
        if(t == 1) a = max(a,x);
        else if(t == 2) b = min(b,x);
        else if(t == 3) c = max(c,y);
        else d = min(d,y);
    }
    if(a >= b || c >= d) cout << 0 << "\n";
    else cout << (b - a) * (d - c) << "\n";
    
}