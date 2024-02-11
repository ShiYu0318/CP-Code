#include <iostream>
#include <math.h>
using namespace std;
/*
2/20
解一元二次方程式
113 29 黃士育
*/
int main()
{
	float a,b,c,D; // D為判別式
	while(cin >> a >> b >> c)
	{
		if (a == 0) return 0; // 無x平方項 直接結束程式
		D = pow(b,2) - 4 * a * c; // D 判別式 = b^2 - 4ac
		/*
		當 D < 0 : 無實數解
		當 D ＝ 0 : 重根
		當 D < 0 : 相異實根
		*/
		if (D < 0) cout << "無實數解\n\n";
		else if (D == 0) cout << "x = " << (-b) / (2 * a) << "（重根）\n\n";
		else 
		{
			cout << "相異實根:\n";
			cout << "x1 = " << ((-b) + sqrt(D)) / (2 * a) << "\n";
			cout << "x2 = " << ((-b) - sqrt(D)) / (2 * a) << "\n\n";
		}
	}
}