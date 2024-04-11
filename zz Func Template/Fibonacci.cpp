// O(n) 費氏數列
int f(int n) 
{
    if (n <= 2) return 1;
    return f(n-1) + f(n-2);
}