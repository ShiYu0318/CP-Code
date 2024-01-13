#include <bits/stdc++.h>
using namespace std;

vector<int> v;

// 可以將底下的某個排序演算法函式複製起來放進來這個區域
// ----------------------------------------------

void merge(int l, int r)
{
    int mid = (l+r)/2, tmp[r-l+1];
    for(int i=l,j=mid+1,k=0; i<=mid || j<=r; ++k)
    {
        if((v[i] <= v[j] && i <= mid) || j > r) tmp[k] = v[i], ++i;
        else tmp[k] = v[j], ++j;
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

// ----------------------------------------------

int main(void)
{
    int n;
    while(cin >> n) v.emplace_back(n);

    // 這行放入某個排序演算法函式名稱 例如：BubbleSort();
    // ------------------------------------------
    MergeSort(0,v.size()-1);
    // ------------------------------------------
    
    for(auto &i : v) cout << i << " ";
    return 0;
}