#include <bits/stdc++.h>
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
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
#define coutE(x) cout << x << "\n";
#define coutS(x) cout << x << ' ';
#define input(x) for(auto &i : x) cin >> i
#define output(x) for(auto &i : x) coutS(i)
#define inputD(x,a,b) FOR(i,0,a) FOR(j,0,b) cin >> x[i][j];
#define YN(x) cout << (x ? "YES" : "NO") << "\n"
#define SET(n) cout << fixed << setprecision(n)
#define f first
#define s second
#define pb push_back
#define nl cout << '\n'
#define rt return
#define ct continue
#define bk break

using namespace std;

void solve()
{	
    vector<int> v;
    FOR(i,0,3)
    {
        int n; cin >> n;
        v.push_back(n);
    }
    sort(all(v));
    output(v)


}

signed main()
{
	ShiYu;
	solve();
	rt 0;
}