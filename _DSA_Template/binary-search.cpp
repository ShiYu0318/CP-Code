//  二分搜尋 x 在 a 中的 index, 不存在則回傳 -1
int binary_search(int a[], int l, int r, int x)
{
    while(l + 1 != r)
    {
        int m = (l + r) / 2;
        if(a[m] == x) return m;
        if(a[m] < x) l = m;
        else r = m;
    }
    return -1;
}