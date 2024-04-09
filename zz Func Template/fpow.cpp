int fpow(int a, int b)
{
    if(b == 1) return a;
    int temp = fpow(a, b/2);
    return (b & 1 ? a : 1) * temp * temp;
}