int fpow(int a, int b)
{
    if(!b) return 1;
    int temp = fpow(a, b/2);
    return (b & 1 ? a : 1) * temp * temp;
}

// 非遞迴版本
// int fpow(int a, int b)
// {
//     int res = 1;
//     while(b)
//     {
//         if(b & 1) res *= a;
//         a *= a;
//         b >>= 1;
//     }
//     return res;
// }