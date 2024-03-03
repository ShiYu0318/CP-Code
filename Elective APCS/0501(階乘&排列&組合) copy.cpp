#include<bits/stdc++.h>
using namespace std;
/*
5/1
113 29 黃士育
階乘
*/
int sum,n,k;

int factorial(int n)
{
    sum = 1;
    for(int i=2;i<=n;i++) sum *= i;
    return sum;
}

int P(int n,int k)
{
    sum = n;
    for(int i=n-1;i>n-k;i--) sum *= i;
    return sum;
}

signed main()
{
    char try_again = 'y';
    int type;
    while(try_again == 'y')
    {
        cout << "請選擇 (1:階乘！; 2:排列P): ";
        cin >> type;
        if(type == 1)
        {
            cout << "請輸入Number: ";
            cin >> n;
            cout << n << "! = " << factorial(n) << "\n";
        }
        else if(type == 2)
        {
            cout << "請輸入 n k : ";
            cin >> n >> k;
            cout << "P " << n << " 取 " << k << " = " << P(n,k) << "\n";
        }
        cout << "再一次？(y/n): ";
        cin >> try_again;
        cout << "\n";
    }
    cout << "已結束程式，若要使用請執行\n";
}