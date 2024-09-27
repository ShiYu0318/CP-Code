#include <bits/stdc++.h>
using namespace std;
#define ll long long

const int N = 1e5+5;
int cnt[N];

int main()
{
    int n,t; cin >> n;
    while(n--)
    {
        cin >> t;
        cnt[t]++; cnt[t+1]++; cnt[t+2]++;
    }
    int mx = -1;
    for(int i=0; i<N; i++) mx = max(mx,cnt[i]);
    cout << mx << "\n";
}