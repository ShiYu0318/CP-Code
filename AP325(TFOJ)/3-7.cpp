// 20260104
#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define F first
#define S second
#define MP make_pair
#define EB emplace_back
#define SZ(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define RPT(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define rFOR(i,n) for(int i=n-1; i>=0; --i)
#define input(x) for(auto &i:x) cin >> i
#define outputN(x,n) RPT(i,n) cout << x[i] << " \n"[i == n-1];
#define output(x) outputN(x,SZ(x))

// 例題 P-3-7. 正整數序列之最接近的區間和
// 滑動窗口

signed main()
{
    ShiYu;
    int n,k; cin >> n >> k;
    vi v(n); input(v);
    int sum = 0, ans = 0, cnt = 0;
    for(int l=0, r=0; r<n; ++r)
    {
        sum += v[r];
        while(sum > k) sum -= v[l++];
        if(sum > ans)
        {
            ans = sum;
            cnt = 1;
        }
        else if(sum == ans) ++cnt;
    }
    cout << ans << '\n' << cnt << '\n';
}