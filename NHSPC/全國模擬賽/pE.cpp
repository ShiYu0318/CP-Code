#include <bits/stdc++.h>
using namespace std;
#define int long long
#define FOR(i,a,b) for(int i=a; i<b; ++i)

int a[200005];

signed main()
{
    int n; cin >> n;
    FOR(i,0,n) cin >> a[i];
    sort(a, a+n);
    int sum = 0;
    FOR(i,0,n / 2) sum += a[i] / 2;
    int s = n / 2;
    if(n % 2)
    {
        s += 1;
        sum += a[n / 2];
    }
    FOR(i,s,n) sum += a[i] * 2;
    cout << sum << '\n';
}