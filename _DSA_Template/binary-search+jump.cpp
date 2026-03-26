// 用跳躍二分搜尋找到 a 中第一個 >= x 的 index
int jump_search(int a[], int n, int x)
{
    if(a[0] >= x) return 0;
    int now = 0;
    for(int jump = n / 2; jump > 0; jump /= 2)
    {
        while(now + jump < n && a[now + jump] < x) now += jump;
    }
    return now + 1;
}