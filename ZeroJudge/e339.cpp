// // 前綴和
// #include <bits/stdc++.h>
// using namespace std;
// #define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
// #define FOR(i,a,b) for(int i=a;i<b;++i)
// #define rFOR(i,n) for(int i=n-1;i>=0;--i)
// #define RPT(i,n) FOR(i,0,n)
// #define input(x) for(auto &i : x) cin >> i
// #define output(x) for(auto &i : x) cout << i << ' '
// #define int long long

// signed main()
// {
//     ShiYu;
//     int n; cin >> n;
    
//     vector<int> a(n),b(n);
//     input(a);
//     b[0] = a[0];
//     FOR(i,1,n) b[i] = b[i-1] + a[i];
//     output(b);
// }

#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+5;
long long A[N], pre[N];

int main()
{
    int n; cin >> n;
    pre[0] = 0;
    for(int i=0; i<n; i++)
    {
        cin >> A[i];
        pre[i+1] = pre[i] + A[i];
    }
    for(int i=1; i<=n; i++)
    {
        cout << pre[i] << " ";
    }
}