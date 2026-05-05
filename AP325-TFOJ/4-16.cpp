// 20260505
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
#define endl '\n'
#define SZ(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define RPT(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define rFOR(i,n) for(int i=n-1; i>=0; --i)
#define input(x) for(auto &i:x) cin >> i
#define outputN(x,n) RPT(i,n) cout << x[i] << " \n"[i == n-1];
#define output(x) outputN(x,SZ(x))

// Q-4-16. 賺錢與罰款
// Greedy 經典題
// 策略：工時短先做（Shortest Job First, SJF）
// 思路：利潤 = 截止時間 - 完工時間，因截止時間固定 要最大化利潤 = 最小化完工時間

signed main()
{
    ShiYu;
    int n; cin >> n;
    vector<pii> v(n);
    for(pii &i : v) cin >> i.F;
    for(pii &i : v) cin >> i.S;
    sort(all(v));
    int t = 0, sum = 0;
    for(pii i : v)
    {
        t += i.F;
        sum += i.S - t;
    }
    cout << sum << "\n";
}

/*
證明：Exchange Argument 交換論證
假設排程中，工作 i 排在工作 j 前面，但 t_i > t_j​（長工作在短工作前）
設這兩個工作開始前，前面所有工作已在時間 S 完成：
交換前（長的先做）：
    C_i = S + t_i
    C_j = S + t_i + t_j
兩者之和 = 2S + 2*t_i + t_j

交換後（短的先做）：
    C_j = S + t_j
    C_i = S + t_j + t_i
兩者之和 = 2S + t_i + 2*t_j

差值 = (2S + 2*t_i + t_j) - (2S + t_i + 2*t_j)
    = t_i - t_j > 0

把短工作移到前面，sum(C_i) 嚴格減少 (t_i - t_j)
任何出現 長工作在短工作前 的排程都可以透過交換來改進
所以 SJF 排序（t 由小到大）是唯一最優排法
*/