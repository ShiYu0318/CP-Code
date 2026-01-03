#include <bits/stdc++.h>
using namespace std;

// 二分搜

vector<string> v;
int n;

int bisearch(string s)
{
    int l = 0, r = n-1, mid;
    while(l <= r)
    {
        mid = (l + r) / 2;
        if(v[mid] == s) return mid;
        else if(v[mid] < s) l = mid + 1;
        else r = mid - 1;
    }
}

int main()
{
    int q; cin >> n >> q;
    v.resize(n); for(auto &i:v) cin >> i;
    sort(all(v));
    while(q--)
    {
        string l,r; cin >> l >> r;
        cout << abs(bisearch(l) - bisearch(r)) - 1 << "\n";
    }
}