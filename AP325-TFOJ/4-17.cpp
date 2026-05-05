// 2026
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

// Q-4-17. 死線高手
// Greedy 經典題
// 策略：按截止時間排序（EDF, Earliest Deadline First）
// 思路：把截止較晚的工作往後移，只會讓它更容易達標，不影響截止較早的工作

signed main()
{
    ShiYu;
    int T; cin >> T;
    while(T--)
    {
        int n; cin >> n;
        vector<pii> v(n);
        for(pii &i : v) cin >> i.S;
        for(pii &i : v) cin >> i.F;
        sort(all(v));
        int t = 0;
        bool b = true;
        for(pii i : v)
        {
            t += i.S;
            if(t > i.F) 
            {
                b = false;
                break;
            }
        }
        cout << (b ? "yes" : "no") << "\n";
    }
}