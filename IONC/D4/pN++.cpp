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
 
 
int qp(int a, int b, int p){
	if(b == 0) return 1;
	if(b == 1) return a%p;
	int tmp = qp(a, b/2, p);
	if(b%2) return tmp%p*tmp%p*a%p;
	else return tmp%p*tmp%p;
}
 
//int g[MN];
 
void sol(){
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; i++) v[i] = i;
	int ans = 0;
	do{
		bool ok = 1;
		vector<vector<bool> > cnt(n + 5, vector<bool>(n + 5, 0));
		//vector<bool> x(n, 0), y(n, 0);
		for(int i = 0; i < n; i++){
			if(
			(i >= 2 && cnt[i - 2][v[i] + 2]) || 
			cnt[i + 2][v[i] + 2] || 
			(v[i] >= 2 && cnt[i + 2][v[i] - 2]) || 
			(i >= 2 && v[i] >= 2 && cnt[i - 2][v[i] - 2])) ok= 0;
			//x[i] = y[v[i]] = 1;
			cnt[i][v[i]] = 1;
		}
		ans+=ok;
	}while(next_permutation(ALL(v)));
	cout << ans << '\n';
 }
signed main()
{
    Cheng0928
    int t;
    t = 1;
    //cin >> t;
    //string ss;
    //getline(cin, ss);
    //init();
    while(t--) sol();
    return 0;
}