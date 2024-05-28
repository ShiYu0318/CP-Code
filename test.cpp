#include <bits/stdc++.h>
using namespace std;

string tob(int n)
{
    string ans;
    while(n > 0)
    {
        if(n % 2 == 1) ans = '1'+ans;
        else ans = '0' + ans;
        n /= 2;
    }
    return ans;
}

int ttot(string s)
{
    int ans=0,n = 1;
    for(int i=s.size()-1;i>=0;--i)
    {
        ans += (s[i]-'0') * n;
        n *= 2;
    }
    return ans;
}

int main()
{
    string s;
    vector<int> v;
    while(getline(cin,s))
    {
        int t = 0;
        for(int i=0;i<s.size();++i)
        {
            if(s[i] == 'o') ++t;
        }
        v.emplace_back(t);
    }
    for(auto i:v) cout << i << ' ';
    cout << '\n';
    int x = v[0];
    for(int i=1;i<v.size();++i) x ^= v[i];
    string k = tob(x);
    cout << x << ' ' << k << '\n';

    string change,ss,ori;
    for(auto i:v)
    {
        ss = tob(i);
        cout << ss << ' ';
        if(ss.size() == k.size() && ss[0] == k[0])
        {
            change = ss;
        }
    }
    int f = ttot(change);
    cout << '\n' << f << " to ";
    f ^= x;
    cout << f << '\n';
}