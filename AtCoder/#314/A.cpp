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
#define nl cout << '\n';
#define coutE(x) cout << x << "\n";
#define coutS(x) cout << x << ' ';
#define YN(x) cout << (x ? "YES" : "NO") << "\n";
#define SET(n) cout << fixed << setprecision(n);
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
	string pi = "3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679";
    int n; cin >> n;
    FOR(i,0,n+2) cout << pi[i];
    nl
}

signed main()
{
	ShiYu;
	solve();
	rt 0;
}