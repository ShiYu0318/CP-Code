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

// AC by cheng

using namespace std;

const int MN = 1e5 + 1;
const int INF = 5e18;
const int MOD = 1e9 + 7;

void sol(){
	int n;
	cin >> n;
	int z = 0;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		if(!x || x < 0) z++;
	}
	if(!z || z == n) cout << "Yes\n";
	else cout << "No\n";
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