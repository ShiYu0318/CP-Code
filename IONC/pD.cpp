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

bool check(vector<int> v, int k, int maxSum) 
{
    int count = 1;
    int currentSum = 0;
    for(int num : v) 
    {
        if(currentSum + num > maxSum) 
        {
            count++;
            currentSum = num;
        } else currentSum += num;
        if (count > k) return false;
    }
    return true;
}

int maxsum(vi v, int k)
{
    int left = *max_element(all(v)), right = 0;
    for(int num : v) right += num;
    
    while(left < right) 
    {
        int mid = left + (right - left) / 2;
        if (check(v, k, mid)) right = mid;
        else left = mid + 1;
    }
    return left;
}

signed main()
{
    ShiYu;
    int n, k; cin >> n >> k;
    vi v(n); input(v);
    cout << maxsum(v, k) << endl;
}