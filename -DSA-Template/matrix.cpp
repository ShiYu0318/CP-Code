struct matrix
{
    int A[2][2]={{0,0},{0,0}};
    matrix operator * (matrix &B){
        matrix res;
        RPT(i,2) RPT(j,2) RPT(k,2) res.A[i][j] += A[i][k] * B.A[k][j];
        return res;
    }
};