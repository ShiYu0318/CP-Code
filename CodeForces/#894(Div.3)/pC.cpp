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
#define YN(x) cout << (x ? "YES" : "NO") << "\n"
#define SET(n) cout << fixed << setprecision(n)
#define input(A) for(auto &x : A) cin >> x
#define output(A) for(auto &x : A) coutS(x)
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
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        stack<int> s;
        int tmp,max;
        FOR(i,0,n)
        {
            cin >> tmp;
            s.push(tmp);
            if(i == 0) max = tmp;
            int a[max][max];
            int b[max][max];
            {
                max = tmp;
                int a[max][max];
                int b[max][max];
                FOR(j,0,max)
                {
                    FOR(k,0,n)
                    {
                        if(k == 0) a[j][k] = 1;
                        else a[j][k] = 0;

                        if(k == n-1) b[k][j] = 1;
                        else b[k][j] = 0;
                    }
                }
            }
            if(i != 0)
            {
                FOR(j,0,tmp)
                {
                    a[i][tmp-j] = 1;
                }
            }
        }

    }
}

signed main()
{
	ShiYu;
	solve();
	rt 0;
}