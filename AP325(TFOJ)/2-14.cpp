// 20260102
#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define F first
#define S second
#define MP make_pair
#define EB emplace_back 
#define endl "\n"
#define SZ(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define RPT(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define rFOR(i,n) for(int i=n-1; i>=0; --i)
#define input(x) for(auto &i:x) cin >> i
#define output(x) for(auto i:x) cout << i << ' '; cout << endl;

// 習題 Q-2-14. 水槽 (108 高中全國賽) (@@)
// 遞迴 排序 思考

vector<pii> h;
vi v; int b, p = 0;
// 習題 Q-2-14. 水槽 (108 高中全國賽) (@@)
void rec(int l, int r, int w)   // 比提示少維護一個注水點參數是因為 注水點永遠固定 它只是用來判斷水先填區間最高擋板的哪側 當某側填滿水時 後續的遞迴呼叫注水點都會在同一側
{
    if(r - l == 1)  // 區間水槽數是 1 則直接倒水回傳
    {
        v[l] = w;
        return;
    }
    else
    {
        while(!(l < h[p].S && h[p].S < r)) ++p;   // 由高到低排序的擋板 找到區間中的那個
        if(w >= h[p].F * (r - l))   // 若水量 >= 區間長 * 區間中最高擋板
        {
            FOR(i,l,r) v[i] = w / (r - l);  // 淹沒區間中所有擋板到平均高度
            return;
        }
        else // 水量不足以淹沒全部則要判斷是否越過區間中最高擋板
        {
            if(b < h[p].S)  // 注水點在最高擋板左側
            {
                if(w <= h[p].F * (h[p].S - l)) rec(l, h[p].S, w);   // 若水量不超過左側容量 不會越過擋板 右側不會有水 縮小區間
                else    // 若會越過擋板 左側裝滿 剩餘水量注入右側
                {
                    FOR(i,l,h[p].S) v[i] = h[p].F;
                    rec(h[p].S, r, w - h[p].F * (h[p].S - l));
                }
            }
            else    // 注水點在最高擋板右側 
            {
                if(w <= h[p].F * (r - h[p].S)) rec(h[p].S, r, w);
                else
                {
                    FOR(i, h[p].S, r) v[i] = h[p].F;
                    rec(l, h[p].S, w -  h[p].F * (r - h[p].S));
                }
            }
        }
    }
}

signed main()
{
    int n,w; cin >> n >> b >> w;
    h.resize(n); v.resize(n-1);
    RPT(i,n)
    {
        cin >> h[i].F;
        h[i].S = i;
    }
    sort(all(h), greater<pii>());
    rec(0,n-1,w);
    output(v);
}