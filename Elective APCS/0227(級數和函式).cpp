#include <iostream>
#include <math.h>
using namespace std;
#define ios_base ::sync_with_stdio(0);cin.tie(0);cout.tie(0);
/* 
級數和計算

函式定義:
1.等差級數 Arithmetic_series() 
2.等比級數 Geometric_series()

變數宣告:
a1 首項
n 項次
d 公差
r 公比
*/

int Arithmetic_series(int a1,int d,int n)
{
	return (2 * a1 + (n - 1) * d) * n / 2;
}

int Geometric_series(int a1,int r,int n)
{
	return a1 * (pow(r,n) - 1) / (r - 1);
}


int main()
{
	int type,a1,d,r,n;
	cout << "1.等差級數\n2.等比級數\n請選擇要進行的運算:\n";
	cin >> type;
	if(type == 1) 
	{
		cout << "請依序輸入 a1首項 d公差 n項次 用空白間隔開:\n";
		cin >> a1 >> d >> n;
		cout << "Sn = " << Arithmetic_series(a1,d,n) << "\n";
	}
	else
	{
		cout << "請依序輸入 a1首項 r公比 n項次 用空白間隔開:\n";
		cin >> a1 >> r >> n;
		cout << "Sn = " << Geometric_series(a1,r,n) << "\n";
	}
}