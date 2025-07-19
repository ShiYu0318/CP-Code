#include <bits/stdc++.h>
#define int long long //TLE or MLE remove
#define F first
#define S second
#define Cheng0928 ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define SIZE(a) signed(a.size())
#define rALL(x) x.rbegin(), x.rend()
#define ALL(x) x.begin(), x.end()
#define PB push_back
#define MP make_pair
 
using namespace std;
 
const int MN = 2e5 + 1;
const int INF = 5e18;
const int MOD = 998244353;
 
//int p[MN][21];
//int deep[MN];
//vector<vector<int> > e(MN);
 
 
 
void sol(){
	int n;
	cin >> n;
	vector<int> dp(n + 1, 0);
	dp[n] = 2;
	for(int i = n - 1; i >= 0; i--){
		dp[i] += dp[i + 1]%MOD, dp[i]%=MOD;
		if(i * 2 <= n && i) dp[i] += dp[i * 2]%MOD, dp[i]%=MOD;
		if(i * 2 + 1 <= n && i) dp[i] += dp[i * 2 + 1]%MOD, dp[i]%=MOD;
		
	}
	cout << dp[0]%MOD << '\n';
 }
signed main()
{
    Cheng0928
    int t;
    t = 1;
    cin >> t;
    //string ss;
    //getline(cin, ss);
    //init();
    while(t--) sol();
    return 0;
}
//