#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define F first
#define S second
#define EB emplace_back
#define endl '\n'
#define nl cout << '\n'
#define SZ(x) ((int)x.size())
#define all(x) x.begin(), x.end()
#define RPT(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define rFOR(i,n) for(int i=n-1; i>=0; --i)
#define input(x) for(auto &i:x) cin >> i
#define output(x) for(auto i:x) cout << i << ' '; nl
#define outputN(x,n) RPT(i,n) cout << x[i] << " \n"[i == n-1];
#define Yn(x) cout << (x ? "Yes" : "No") << '\n';

const int N = 1001;
int ans[N], guess[N];

signed main()
{
    ShiYu;
    int n, t = 1;
    while(cin >> n && n)
    {
        set<int> st;
        int cnt_ans[10] = {0};
        RPT(i,n)
        {
            cin >> ans[i];
            st.insert(ans[i]);
            cnt_ans[ans[i]]++;
        }
        cout << "Game " << t++ << ":\n";
        while(cin >> guess[0])
        {
            FOR(i,1,n) cin >> guess[i];
            if(!guess[0]) break;
            int A = 0, B = 0, cnt_guess[10] = {0};
            RPT(i,n)
            {
                if(guess[i] == ans[i])
                {
                    ++A;
                    cnt_guess[ans[i]]++;
                }
            }
            RPT(i,n)
            {
                if(guess[i] != ans[i] && st.count(guess[i]) && cnt_guess[guess[i]] < cnt_ans[guess[i]])
                {
                    ++B;
                    cnt_guess[guess[i]]++;
                }
            }
            cout << "    (" << A << "," << B << ")\n";
        }
    }
}