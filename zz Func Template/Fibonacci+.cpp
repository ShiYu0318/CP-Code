// O(log n) 費氏數列 w/ 矩陣快速冪 + struct
struct matrix
{
    int A[2][2] = {{0,0},{0,0}};
    matrix operator * (matrix &B)
    {
        matrix res;
        RPT(i,2) RPT(j,2) RPT(k,2) res.A[i][j] += A[i][k] * B.A[k][j];
        return res;
    }
} M = {1,1,1,0};

matrix fpow(int n)
{
    if(n == 0 || n == 1) return M;
    matrix t = fpow(n/2), tt = t * t;
    return (n & 1 ? M * tt : tt);
}

signed main()
{
    ShiYu;
    int n; cin >> n;
    cout << fpow(n-1).A[0][0] << '\n';
}