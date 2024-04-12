#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define input(x,n) FOR(i,0,n) cin >> x[i];
#define dbg(x) cout << #x << "=" << x << ' ';
#define int long long
#define nl cout << "\n";
#define Yn(x) cout << (x ? "Yes" : "No") << "\n";

signed main()
{
	int n,y; cin >> n >> y;
    bool b[100];
    FOR(i,0,n) b[i] = false;
    int t, ans = 0;
    FOR(i,0,y)
    {
        cin >> t;
        b[t] = true;
    }
    FOR(i,0,n)
    {
        if(b[i])
        {
            ans++;
            continue;
        }
        cout << i << "\n";
        
    }
    cout << "Mario got " << ans << " of the dangerous obstacles.\n";
}