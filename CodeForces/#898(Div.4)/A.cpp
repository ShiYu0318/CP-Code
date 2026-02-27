#include <bits/stdc++.h>
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FOR(i,n) for(int i=0;i<n;++i)
#define input(x) for(auto &i : x) cin >> i
#define output(x) for(auto &i : x) coutS(i)
#define YN(x) cout << (x ? "YES" : "NO") << '\n'
#define nl cout << '\n'
using namespace std;

void solve()
{	
	int n; cin >> n;
    string s;
    while(n--)
    {
        cin >> s;
        if(s[0]=='a'&&s[1]=='b'&&s[2]=='c' ||s[0]=='a'&&s[1]!='b'&&s[2]!='c'||s[0]!='a'&&s[1]=='b'&&s[2]!='c'||s[0]!='a'&&s[1]!='b'&&s[2]=='c')
        {
            cout << "YES\n";
        }
        else cout << "NO\n";
    }
}

signed main()
{
	ShiYu;
	solve();
	return 0;
}