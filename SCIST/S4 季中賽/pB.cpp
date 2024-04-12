#include <bits/stdc++.h>
#define ShiYu ios_base::sync_with_stdio(0),cin.tie(0);
#define int long long
#define ull unsigned long long
#define pii pair<int,int>
#define vii vector<pii>
#define pq priority_queue
#define pq_min priority_queue<int,vector<int>,greater<int>> 
#define F first
#define S second
#define EB emplace_back
#define MP(a,b) make_pair(a,b)
#define SZ(x) ((ll)x.size())
#define all(x) x.begin(), x.end()
#define MMn maxn = INT_MIN, minn = INT_MAX
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
#define remax(a, b) a = (a > b ? a : b)
#define remin(a, b) a = (a < b ? a : b)
#define coutE(x) cout << x << "\n"
#define coutS(x) cout << x << ' '
#define dbg(x) cerr << #x << "=" << x << "\n";
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define rFOR(i,n) for(int i=n-1;i>=0;--i)
#define RPT(i,n) FOR(i,0,n)
#define input(x) for(auto &i : x) cin >> i
#define inputn(x,n) RPT(i,n) cin >> x[i] 
#define inputD(x,a,b) RPT(i,a) RPT(j,b) cin >> x[i][j]
#define output(x) for(auto i : x) cout << i << " "
#define YN(x) cout << (x ? "YES" : "NO") << "\n"
#define Yn(x) cout << (x ? "Yes" : "No") << "\n"
#define yn(x) cout << (x ? "yes" : "no") << "\n"
#define islower(x) ((x) >= 'a' && (x) <= 'z')
#define isupper(x) ((x) >= 'A' && (x) <= 'Z')
#define isletter(x) (islower(x) || isupper(x))
#define SET(n) cout << fixed << setprecision(n)
#define nl(n) RPT(i,n) cout << "\n"
const double eps = 1e-8;
using namespace std;
 
// 模擬 20%
 
//==========================================================================================
 
vector<string> tb;
int top[100];
 
void solve()
{
    int n,m,q; cin >> n >> m >> q;
    string ts;
    RPT(i,m) ts += "0";
    RPT(i,n) tb.EB(ts);
    int h,w,p,ans = 0;
    RPT(i,q)
    {
        cin >> h >> w >> p;
        int maxtop = -1;
        FOR(j,p,p+w) maxtop = max(maxtop,top[j-1]); // 找最高卡點
        int newtop = maxtop + h; // 紀錄新高點
        if(newtop > n) // GG
        {
            cout << "Game Over\n";
            return;
        }
        FOR(j,maxtop,newtop) // 放置
        {
            FOR(k,p,p+w) tb[j][k-1] = '1';
        }
        rFOR(j,n)   // 判斷消除
        {
            bool remove = true;
            RPT(k,m)
            {
                if(tb[j][k] == '0') remove = false;
            }
            if(remove)
            {
                --newtop;
                ++ans;
                tb.erase(tb.begin()+j);
                tb.EB(ts);
            }
        }
        FOR(j,p,p+w) top[j-1] = newtop; // 更新最高點
    }
    cout << ans << "\n";
    rFOR(i,n)
    {
        RPT(j,m)
        {
            if(tb[i][j] == '0') cout << '.';
            else cout << '#';
        }
        cout << "\n";
    }
}
 
signed main(void)
{
    ShiYu;
    int t = 1; // cin >> t;
    while(t--) solve();
}
