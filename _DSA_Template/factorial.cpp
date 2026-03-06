// 階乘
int fac(int n) 
{
    if (n == 1) return 1;
    return n * fac(n-1);
}