#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
    int n,q,l,r,k,sum=0;
    cin >> n >> q;
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    while(q--)
    {
        cin >> l >> r >> k;
        sum = 0;
        for(int i=l;i<=r;i++)
        {
            sum += abs(k - a[i-1]) + (k + a[i-1]);
        }
        cout << sum << "\n";
    }

	return 0;
}