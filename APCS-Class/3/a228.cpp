#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define int long long
#define endl '\n'
#define END "ENDPROGRAM"
#define S "S"
#define IF "IF"
#define ELSE "ELSE"
#define ENDIF "END_IF"

int f(string end)
{
	int ret = 1, temp = 0;
	string t;
	while(cin >> t)
	{
		if(t == S) continue;
		if(t == end) break;
		if(t == IF)
		{
			temp = f(ELSE);
			temp += f(ENDIF);
			ret *= temp;
		}
	}
	return ret;
}

signed main()
{
    ShiYu;
	int te; cin >> te;
	while(te--) cout << f(END) << endl;
}