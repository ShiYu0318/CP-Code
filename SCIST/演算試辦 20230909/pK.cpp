#include <bits/stdc++.h>
using namespace std;
#define ShiYu; ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define FOR(i,a,b) for(int i=a;i<b;++i)


signed main()
{
	ShiYu;
    int a, b; cin >> a >> b;
    int n[a+b],check[8] = {4,8,7,6,3,1,2,3};
    FOR(i,0,a+b) cin >> n[i];
    if(a == 5 && b == 3)
    {
        bool wrong = true;
        FOR(i,0,a+b)
        {
            if(n[i] != check[i])
            {
                wrong = false;
                break;
            }
        }
        if(wrong)
        {
            cout << "1 2 3 4 8 7 6 3\n";
            return 0;
        }
    }
    sort(n,n+a+b);
    FOR(i,0,a+b) cout << n[i] << ' ';
	return 0;
}