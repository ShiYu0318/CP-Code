#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define FOR(i,a,b) for(int i=a; i<b; ++i)
#define ShiYu ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
constexpr int mod = 1e9 + 7;

ll fpow(ll i, int j) 
{
	ll ret = 1, tmp = i;
	for (; j; j >>= 1, tmp = tmp * tmp % mod)
		if (j & 1) ret = ret * tmp % mod;
	return ret;
}

bool IsPowerOfTwo(int n)
{
    return (n > 0) && ((n & (n - 1)) == 0);
}

bool IsSumOfTwoPowerOfTwo(int n)
{
    int p = 0,t = n;
    t /= 2;
    while(t > 0)
    {
        p++;
        t /= 2;
    }
    FOR(i,0,p)
    {
        int k = n - fpow(2,i);
        if(IsPowerOfTwo(k)) return true;
    }
    return false;
}

signed main()
{
    ShiYu
    int n; cin >> n;
    while(n--)
    {
        int a; cin >> a;
        queue<int> q;
        FOR(i,1,a+1) q.push(i);
        int f = 0, c = 1, b; // f 出局人數,c 目前喊到的數字, b 沒事的人 排到後面
        while(q.size() > 1)
        {
            if(IsSumOfTwoPowerOfTwo(c))
            {
                cout << q.front() << ' ';
                q.pop();
            }
            else
            {
                b = q.front();
                q.pop();
                q.push(b);
            }
            c++;
        }
        cout << "\n";
    }
}