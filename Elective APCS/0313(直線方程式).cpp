#include<bits/stdc++.h>
using namespace std;
/*
11329 黃士育 2023/03/13
輸入A(x1,y1),B(x2,y2)
1.求中點 C(x3,y3)
2.求直線方程式 ax + by + c = 0 or y = mx + b
3.輸入D(x4,y4) 求點到直線距離d(D,L)
*/
int main()
{
	float x1,y1,x2,y2,x3,y3,x4,y4,m,k,a,b,c,D;
	// 輸入A(x1,y1),B(x2,y2)
	cout << "輸入A(x1,y1),B(x2,y2):\n";
	cin >> x1 >> y1 >> x2 >> y2;
	cout << "A(" << x1 << "," << y1 << "),B(" << x2 << "," << y2 << ")\n\n";
	//1.求中點 C(x3,y3)
	x3 = (x1 + x2) / 2;
	y3 = (y1 + y2) / 2;
	cout << "中點C(" << x3 << "," << y3 << ")\n\n";
	// 2.求直線方程式 ax + by + c = 0 or y = mx + b
	m = (y2 - y1) / (x2 - x1);
	k = y1 - (m * x1);
	cout << "直線方程式L:\ny = ";
	if(m != 1) cout << m;
	cout << "x";
	if(k != 0)
	{
		if(k > 0) cout << "+" << k;
		else cout << k;
	}
	
	cout << "\nor\n";	
	
	if(m - (int)m == 0)
	{
		a = m;
		b = -1;
		c = k;
	}
	else
	{
		  a = y2 - y1;
		  b = -(x2 - x1);
		  c = k * (x2 - x1);
	}
	if(a == 1);
	else if(a == -1) cout << "-";
	else cout << a;
	cout << "x";
	
	if(b == 1);
	else if(b == -1) cout << "-";
	else cout << b;
	cout << "y";
	
	if(c != 0)
	{
		if(c > 0) cout << "+" << c;
		else cout << c;
	}
	cout << " = 0\n\n";
	// 3.輸入D(x4,y4) 求點到直線距離d(D,L)
	cout << "輸入D(x,y):\n";
	cin >> x4 >> y4;
	cout << "D(" << x4 << "," << y4 << ")\n";
	D = abs(a*x4 + b*y4 + c) / sqrt(pow(a,2) + pow(b,2));
	cout << "d(D,L) = " << D << "\n";
}