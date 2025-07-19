#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define rFOR(i,n) for(int i=n-1;i>=0;--i)
#define RPT(i,n) FOR(i,0,n)
#define input(x) for(auto &i : x) cin >> i
#define output(x) for(auto i : x) cout << i << ' '
#define Yn(x) cout << (x ? "Yes" : "No") << '\n';
#define all(x) x.begin(),x.end()
#define int long long
#define F first
#define S second

signed main()
{
    ShiYu;
    int n; cin >> n;
    int t,x;
    queue<int> q;
    while(n--)
    {
        cin >> t;
        if(t == 1)
        {
            cin >> x;
            q.emplace(x);
        }
        else if(t == 2)
        {
            cout << (q.empty() ? -1 : q.front()) << '\n';
        } 
        else if(!q.empty()) q.pop();
    }
}



#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n,t,x; cin >> n;
    queue<int> q;
    while(n--)
    {
        cin >> t;
        if(t == 1)
        {
            cin >> x;
            q.emplace(x);
        }
        else if(t == 2)
        {
            if(q.empty()) cout << "-1\n";
            else cout << q.front() << "\n";
        } 
        else if(!q.empty()) q.pop();
    }
}