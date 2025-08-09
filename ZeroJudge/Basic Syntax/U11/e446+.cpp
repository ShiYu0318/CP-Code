#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define rFOR(i,n) for(int i=n-1;i>=0;--i)
#define RPT(i,n) FOR(i,0,n)
#define input(x) for(auto &i : x) cin >> i
#define output(x) for(auto &i : x) cout << i << ' '
#define Yn(x) cout << (x ? "Yes" : "No") << '\n';
#define all(x) x.begin(),x.end()
#define int long long


signed main()
{
    ShiYu;
    int n; cin >> n;
    int arr[n];
    for(int i=0; i<n; ++i) arr[i] = i+1;
    do {
        for(int i=0; i<n; ++i) cout << arr[i] << " \n"[i==n-1];
    } while (next_permutation(arr.begin(), arr.end()));
}