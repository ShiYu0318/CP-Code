int fpow(int a, int b)
{
    if(b == 1) return a;
    int temp = fpow(a, b/2);
    return (n%2 ? a : 1) * temp * temp;
}