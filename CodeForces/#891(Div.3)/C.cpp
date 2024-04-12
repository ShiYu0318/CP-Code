#include <bits/stdc++.h>
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define str string
#define pq priority_queue<int>
#define pq_min priority_queue < int, vector<int>, greater<int> > 
#define sz(x) ((ll)x.size())
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp(a,b) mack_pair(a,b)
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define rFOR(i,a,b) for(int i=a-1;i>=b;--i)
#define nl cout << '\n';
#define coutE(x) cout << x << '\n';
#define coutS(x) cout << x << ' ';
#define YN(x) cout << (x ? "NO" : "YES") << '\n';
#define SET(n) cout << fixed << setprecision(n)
#define input(A) for(auto &x : A) cin >> x;
#define output(A) for(auto &x : A) coutS(x);
#define f first
#define s second
#define pb push_back
#define rt return
#define ct continue;
#define bk break;
#pragma GCC diagnostic ignored "-Wc++11-extensions"

using namespace std;

void solve()
{	
    vector<int> b;
    ll n; cin >> n;
    ll nb = (n * (n - 1)) / 2,tmp,max=0;
    FOR(i,0,nb)
    {
        cin >> tmp;
        if(tmp > max) max = tmp;
        b.pb(tmp);
    }
    sort(all(b));   
    // output(b)
    int m = n - 1;
    for(int i=0;i<nb;)
    {
        coutS(b[i])
        i += m;
        m--;
    }
    coutE(max)
}

signed main()
{
	ShiYu;
    ll t; cin >> t;
    while(t--) solve();
	rt 0;
}
/*
用最後一個測資來看
題目給 洗牌過後的 B 陣列
3 0 0 -2 0 -2 0 0 -2 -2
排序完後的 B陣列
-2 -2 -2 -2 0 0 0 0 0 3 3

因為 n = 5
所以假設原 A 陣列 = [ , , , , ]
當 最小的 -2 放第一個
A = [-2, , , , ]
跟後面的每個比較 都會產生一個自己
所以會產生 4 個 -2
我們可以 刪掉 B陣列 裡面 4 個 -2
B陣列 剩下
0 0 0 0 0 3 3

接著第二個數字放 0 
a = [-2,0, , , ]
跟後面的比較完會產生 3 個 0
就把 B陣列 刪掉 3 個 0 
B陣列 剩下
0 0 3 3

以此類推
A = [-2,0,0, , ]
B 剩 3 3

A = [-2,0,0,3, ]
B 剩 3

A = [-2,0,0,3,3]
*/