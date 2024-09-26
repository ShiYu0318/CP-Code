#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e5;
ll rec[N];

int f(int n)
{
    int t = n;
    while(t != 0)
    {
        n += t % 10;
        t /= 10;
    }
    return n % N;
}

int main()
{
    int n; ll k,i; cin >> n >> k;
    for(i=1; i<=k; i++)
    {
        n = f(n);
        if(rec[n] > 0) break;
        else rec[n] = i;
    }
    int r = i - rec[n];
    if(!r) cout << n << "\n";
    else
    {
        int lave = (k-i) % r;
        while(lave--) n = f(n);
        cout << n << "\n";
    }
}