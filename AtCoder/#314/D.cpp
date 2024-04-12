#include <bits/stdc++.h>
#define ShiYu ios::sync_with_stdio(0); cin.tie(0)
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
    ll n; cin >> n;
    str s; cin >> s;
    ll q; cin >> q;
    ll t,x; char c;
    while(q--)
    {
        cin >> t >> x >> c;
        if(t == 1)
        {
            s[x-1] = c;
        }
        else if(t == 2)
        {
            
            for(int i=0;i<n;++i)
            {
                s[i] = tolower(s[i]);
            }
        }
        else
        {
            for(int i=0;i<n;++i)
            {
                s[i] = toupper(s[i]);
            }
        }
    }
    cout << s << "\n";
}

signed main()
{
	ShiYu;
	solve();
	rt 0;
}