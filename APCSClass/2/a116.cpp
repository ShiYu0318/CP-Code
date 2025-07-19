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

// 爛題

tm add_days(const tm& date, int days) 
{
    tm new_date = date;
    time_t t = mktime(&new_date);
    t += days * 24 * 60 * 60;
    new_date = *localtime(&t);
    return new_date;
}

void print_date(const tm& date) 
{
    string s;
    cout << date.tm_year + 1900 << '/';
    if(date.tm_mon + 1 < 10) cout << '0';
    cout << date.tm_mon + 1 << '/';
    if(date.tm_mday < 10) cout << '0';
    cout << date.tm_mday << '\n';
}

int GCD(int a, int b)
{
    if(b==0) return a;
    else return GCD(b, a%b);
}

signed main()
{
    ShiYu;
    int n,a,b,t; cin >> n >> a;
    RPT(i,n-1)
    {
        cin >> b;
        t = GCD(a,b);
        a = a / t * b;
    }
    tm date = {};
    string d; cin >> d;
    date.tm_year = stol(d.substr(0,4)) - 1900;
    date.tm_mon = stol(d.substr(5,2)) - 1;
    date.tm_mday = stol(d.substr(8));
    tm new_date = add_days(date, a);
    print_date(new_date);
}

