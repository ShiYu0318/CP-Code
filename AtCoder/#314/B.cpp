#include <bits/stdc++.h>
#define ShiYu ios::sync _with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long 
#define ull unsigned long long
#define str string
#define pq priority_queue<int>
#define pq_min priority_queue < int, vector<int>, greater<int> > 
#define sz(x) ((ll)x.size())
#define all(x) x.begin(), x.end()
#define mp(a,b) mack_pair(a,b)
#define FOR(i,a,b) for(ll i=a;i<b;++i)
#define rFOR(i,a,b) for(ll i=a-1;i>=b;--i)
#define nl cout << "\n";
#define coutE(x) cout << x << "\n";
#define coutS(x) cout << x << ' ';
#define YN(x) cout << (x ? "YES" : "NO") << "\n";
#define SET(n) cout << fixed << setprecision(n)
#define input(A) for(auto &x : A) cin >> x;
#define output(A) for(auto &x : A) coutS(x);
#define f first
#define s second
#define pb push_back
#define rt return
#define ct continue;
#define bk break;

using namespace std;

void solve()
{	
    ll n; cin >> n;
    vector<set<int>> v;
    map<int,int> m;
    for(int i=0;i<n;++i)
    {
        ll c; cin >> c;
        m[i] = c;
        set<int> a;
        while(c--)
        {
            ll t; cin >> t; 
            a.emplace(t);
        }
        v.pb(a);
    }
    ll x; cin >> x;
    vector<int> bet;
    for(int i=0;i<n;++i)
    {
        if(v[i].find(x) != v[i].end()) bet.pb(i);
    }
    if(bet.size() == 0) coutE(0)
    else
    {
        ll min = m[0];
        for(int i=0;i<bet.size();++i)
        {
            if(m[bet[i]] < min) min = m[bet[i]];
        }
        vector<int> ans;
        for(int i=0;i<bet.size();++i)
        {
            if(m[bet[i]] == min) ans.pb(bet[i]+1);
        }
        coutE(ans.size())
        output(ans)
        nl
    }
}

signed main()
{
	ShiYu;
	solve();
	rt 0;
}