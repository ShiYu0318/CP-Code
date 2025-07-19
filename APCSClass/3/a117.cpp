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

int t;

void move(int n, char from, char to, char by)
{
    if(n < 1) return;
    move(n-1,from,by,to);
    cout << " ring " << n << " : " << from << " => " << to << endl; t++;
    move(n-1,by,to,from);
}

void honai(int n, char from, char to, char by)
{
    if(n < 1) return;
    move(n-1,from,by,to);
    cout << " ring " << n << " : " << from << " => " << to << endl; t++;
    honai(n-2,by,from,to);
}
signed main(){
    ShiYu;
    int n; cin >> n;
    honai(n,'A','C','B');
    cout << "共需" << t << "個移動" << endl;
}
