#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0)
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define rFOR(i,n) for(int i=n-1;i>=0;--i)
#define RPT(i,n) FOR(i,0,n)
#define input(x) for(auto &i : x) cin >> i
#define output(x) for(auto i : x) cout << i << ' '
#define Yn(x) cout << (x ? "Yes" : "No") << "\n";
#define all(x) x.begin(),x.end()
#define int long long
#define F first
#define S second

// 逆序數對 合併排序

int ans;
vector<int> v; 

void merge(int l, int r)
{
    int mid = (l+r)/2, tmp[r-l+1];
    for(int i=l,j=mid+1,k=0; i<=mid || j<=r; ++k)
    {
        if((v[i] <= v[j] && i <= mid) || j > r) 
        {
            tmp[k] = v[i++];
        }
        else
        {
            tmp[k] = v[j++];
            ans += mid - i + 1;
        }
    }
    for(int i=l,j=0; i<=r; ++i,++j) v[i] = tmp[j];
}

void MergeSort(int l, int r)
{
    if(l == r) return;
    int mid = (l+r)/2;
    MergeSort(l,mid); MergeSort(mid+1,r);
    merge(l,r);
}

signed main()
{
    ShiYu;
    int n; cin >> n;
    int x;
    RPT(i,n)
    {
        cin >> x;
        v.emplace_back(x);
    }
    MergeSort(0,v.size()-1);
    cout << ans << "\n";
    // output(v);
}
