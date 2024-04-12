// 建表 模擬 10%
#include <bits/stdc++.h>
#define ShiYu ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define ll long long
#define ull unsigned ll
#define int ll
#define vii vector<pair<int, int>>
#define pq priority_queue
#define pq_min priority_queue < int, vector<int>, greater<int> > 
#define MMn maxn = INT_MIN, minn = INT_MAX
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define remax(a, b) a = (a > b ? a : b)
#define remin(a, b) a = (a < b ? a : b)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(), x.end()
#define mp(a,b) make_pair(a,b)
#define dbg(x) cerr << #x << "=" << x << endl
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define FORn(i,n) for(int i=0;i<n;++i)
#define rFOR(i,n) for(int i=n-1;i>=0;--i)
#define coutE(x) cout << x << "\n"
#define coutS(x) cout << x << ' '
#define input(x) for(auto &i : x) cin >> i
#define inputn(x,n) FORn(i,n) cin >> x[i] 
#define output(x) for(auto &i : x) dbg(i)
#define inputD(x,a,b) FORn(i,a) FORn(j,b) cin >> x[i][j]
#define YN(x) cout << (x ? "YES" : "NO") << "\n"
#define Yn(x) cout << (x ? "Yes" : "No") << "\n"
#define yn(x) cout << (x ? "yes" : "no") << "\n"
#define SET(n) cout << fixed << setprecision(n)
#define F first
#define S second
#define pb push_back
#define nl cout << "\n"
const double eps = 1e-8;
using namespace std;

//==========================================================================================

string t[7];
const int mx[] = {1,2,2,1,-1,-2,-2,-1},
          my[] = {2,1,-1,-2,-2,-1,1,2};
int r,c;


bool in_range(int x, int y)
{
    return x >= 0 && x < r && y >= 0 && y < c; 
}

void solve()
{
    cin >> r >> c;
    inputn(t,r);
    bool gg = false,rd = 0; // 0 = Charlie, 1 = Dave
    while(!gg)
    {
        gg = true;
        FORn(i,r)
        {
            FORn(j,c)
            {
                if(t[i][j] == '@')
                {
                    FORn(k,8)
                    {
                        int x = i + mx[k], y = j + my[k];
                        if(in_range(x, y) && t[x][y] == '@')
                        {
                            t[i][j] = '#';
                            t[i + mx[k]][j + my[k]] = '#';
                            rd = 1 - rd;
                            gg = false;
                            break;
                        }
                    }
                }
            }
        }
    }
    cout << (rd ? "Charlie" : "Dave") << "\n";
}

signed main(void)
{
	ShiYu;
	solve();
}