#include <bits/stdc++.h>
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define ull unsigned long long
#define pii pair<int,int>
#define vii vector<pii>
#define pq priority_queue
#define pq_min priority_queue<int,vector<int>,greater<int>> 
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
#define dbg(x) cerr << #x << "=" << x << '\n';
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define rFOR(i,n) for(int i=n-1;i>=0;--i)
#define RPT(i,n) FOR(i,0,n)
#define input(x) for(auto &i : x) cin >> i
#define inputn(x,n) RPT(i,n) cin >> x[i] 
#define inputD(x,a,b) RPT(i,a) RPT(j,b) cin >> x[i][j]
#define output(x) for(auto i : x) cout << i << ' '
#define YN(x) cout << (x ? "YES" : "NO") << '\n'
#define Yn(x) cout << (x ? "Yes" : "No") << '\n'
#define yn(x) cout << (x ? "yes" : "no") << '\n'
#define islower(x) ((x) >= 'a' && (x) <= 'z')
#define isupper(x) ((x) >= 'A' && (x) <= 'Z')
#define isletter(x) (islower(x) || isupper(x))
#define SET(n) cout << fixed << setprecision(n)
#define nl(n) RPT(i,n) cout << '\n'
const double eps = 1e-8;
using namespace std;

// 字串 枚舉

//==========================================================================================

// 1:a>b, -1:a<b, 0:a==b
int cmp(string a, string b) 
{
    if(a.size() > b.size()) return 1;
    if(a.size() < b.size()) return -1;
    RPT(i,a.size())
    {
        if(a[i] > b[i]) return 1;
        if(a[i] < b[i]) return -1;
    }
    return 0;
}

string dis(string a, string b)
{
    string s;
    bool tmp = false;
    rFOR(i,a.size())
    {
        int t;
        if(tmp)
        {
            if(b[i] != '0')
            {
                --b[i];
                tmp = false;
            }
            else
            {
                s += "0"+(10 - (a[i]-'0') - 1);
                continue;
            }
        }
        if(a[i] <= b[i]) t = b[i] - a[i];
        else
        {
            t = 10 - (a[i]-'0') + (b[i]-'0');
            tmp = true;
        }
        s += (char)('0'+t);
    }
    while(s.back() == '0') s.pop_back();
    reverse(all(s));
    return s;
}

// bool GG(string a, string b)
// {
//     sort(all(a)); sort(all(b));
//     reverse(all(a)); reverse(all(b));
//     if(cmp(a,b) == 1) return true;
//     else return false;
// }

void solve()
{
    
    string a,b; cin >> a >> b;
    if(cmp(a,b) == 0) cout << 0 << "\n";
    else
    {
        sort(all(b));
        string ans = "-1";
        do
        {
            if(a == b) // 重排列跟原數一樣
            {
                ans = "0";
                break;
            }
            else if(b[0] == '0' || cmp(a,b) == 1) continue; // 有前綴 0 或 a > b 跳過 
            else
            {
                string ts = dis(a,b);
                if(ans == "-1") ans = ts; 
                if(cmp(ans,ts) == 1) ans = ts;;
            }
        } while(next_permutation(all(b)));
        cout << ans << '\n';
    }
}

signed main(void)
{
    ShiYu;
    solve();
}