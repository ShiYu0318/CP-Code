#include <bits/stdc++.h>
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define ull unsigned ll
#define int ll
#define pii pair< int, int >
#define vii vector< pii >
#define pq priority_queue
#define pq_min priority_queue < int, vector<int>, greater<int> > 
#define F first
#define S second
#define eb emplace_back
#define mp(a,b) make_pair(a,b)
#define sz(x) ((ll)x.size())
#define all(x) x.begin(), x.end()
#define MMn maxn = INT_MIN, minn = INT_MAX
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define remax(a, b) a = (a > b ? a : b)
#define remin(a, b) a = (a < b ? a : b)
#define coutE(x) cout << x << '\n'
#define coutS(x) cout << x << ' '
#define dbg(x) cerr << #x << "=" << x << '\n';
#define RPT(i,n) for(int i=0;i<n;++i)
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define rFOR(i,n) for(int i=n-1;i>=0;--i)
#define input(x) for(auto &i : x) cin >> i
#define inputn(x,n) RPT(i,n) cin >> x[i] 
#define inputD(x,a,b) RPT(i,a) RPT(j,b) cin >> x[i][j]
#define output(x) for(auto &i : x) dbg(i)
#define YN(x) cout << (x ? "YES" : "NO") << '\n'
#define Yn(x) cout << (x ? "Yes" : "No") << '\n'
#define yn(x) cout << (x ? "yes" : "no") << '\n'
#define SET(n) cout << fixed << setprecision(n)
#define nl(n) RPT(i,n) cout << '\n'
const double eps = 1e-8;
using namespace std;

//==========================================================================================

// AC

const int mx[4] = {0,-1,0,1},
          my[4] = {-1,0,1,0};

int n,tb[45][45];

bool in_range(int x, int y)
{
    return (x >= 0 && y >= 0 && x < n && y < n);
}

int create(int n)
{
    /*
    順時針轉圈的方法
    mi 上下左右 if mi == 4 mi = 0
    t 這個方向要走幾步
    tt 這個方向已經走幾步了 if tt == t mi++ r-- tt=0 
    r 每轉方向 2 次就要多走 1 步 if r==0 t++ r=2
    */
    int x = n / 2, y = x;
    int mi=0,t=1,tt=0,r=2;
    // cout << x << "=" << y << '\n';
    FOR(i,1,n*n)
    {
        x += mx[mi];
        y += my[mi];
        // cout << x << ' ' << y << '\n';
        if(!in_range(x,y)) return 0;
        if(x == n/2 && y == n/2) continue;
        tb[x][y] = i;
        tt++;
        if(tt == t)
        {
            mi++;
            if(mi == 4) mi = 0;
            r--;
            if(r == 0)
            {
                t++;
                r = 2;
            }
            tt = 0;
        }
    }
    return 0;
}


void solve()
{
    cin >> n;
    create(n);
    RPT(i,n)
    {
        RPT(j,n)
        {
            if(i == n/2 && j == n/2) cout << "T ";
            else cout << tb[i][j] << ' ';
        }
        cout << '\n';
    }
}

signed main(void)
{
	ShiYu;
	solve();
}