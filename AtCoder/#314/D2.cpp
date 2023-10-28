#include<bits/stdc++.h>

#define ShiYu ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define ll long long
#define ull unsigned long long
#define str string
#define pq priority_queue<int>
#define pq_min priority_queue < int, vector<int>, greater<int> > 
#define sz(x) ((ll)x.size())
#define all(x) x.begin(), x.end()
#define mp(a,b) mack_pair(a,b)
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define rFOR(i,a,b) for(int i=a-1;i>=b;--i)
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
    int n; cin >> n;
    str s; cin >> s;
    int q; cin >> q;
    int t,x; char c;
    vector<map<int,pair<int,char>>> v;
    while(q--)
    {
        cin >> t >> x >> c;
        
        v.pb(make_pair(t,make_pair(x,c)));
    }
    int type = 0,end = 0;
    // 找最後的字串為大寫或小寫
    for(int i=v.size()+1;i>=0;--i)
    {
        if(v[i] == 2 || v[i] == 3)
        {
            type = v[i];
            end = i;
            break;
        }
    }
    for(auto& i : m) s[i.f-1] = i.s;


}

signed main()
{
	ShiYu
	solve();
	rt 0;
}