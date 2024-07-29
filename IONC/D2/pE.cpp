#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define F first
#define S second
#define EB emplace_back
#define endl '\n'
#define nl cout << '\n'
#define SZ(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define RPT(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define rFOR(i,n) for(int i=n-1; i>=0; --i)
#define input(x) for(auto &i:x) cin >> i
#define output(x) for(auto i:x) cout << i << ' '; nl
#define outputN(x,n) RPT(i,n) cout << x[i] << " \n"[i == n-1];
#define Yn(x) cout << (x ? "Yes" : "No") << '\n';

struct BIT 
{
	int size;
	vector<int> bit;
	BIT(int n) : size(n), bit(n + 1) {}
	void upd(int x, int v) 
    {
		x++;
		for(; x <= size; x += x & (-x)) bit[x] += v;
	}
	int query(int b) 
    {
		b++;
		int res = 0;
		for(; b > 0; b -= b & (-b)) res += bit[b];
		return res;
	}
};

signed main()
{
    ShiYu;
    int n,q; cin >> n >> q;
    vi v(n); input(v);
    vector<vector<pii>> qq(n);
    RPT(i,q)
    {
        int a,b; cin >> a >> b;
        qq[a-1].push_back({b-1,i});
    }
    BIT bit(n);
    map<int,int> mp;
    vi ans(q,-1);
    rFOR(i,n)
    {
        int t = v[i];
        if(mp.count(t)) bit.upd(mp[t],-1);
        mp[t] = i; bit.upd(i,1);
        for(auto &q:qq[i]) ans[q.S] = bit.query(q.F);
    }
    for(auto i:ans) cout << i << endl;
}