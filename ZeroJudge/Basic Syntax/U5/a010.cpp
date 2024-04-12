#include <iostream>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0)

int main()
{
	int n,x=2,t;
	cin >> n;
	while (n >= 2)
	{
		//重置因數次方
		t = 0;
		//持續除一個因數直到不能整除
		while (n % x == 0)
		{
			n /= x;
			t++;
		}
		//有找出因數就輸出
		if (t > 0)
		{
			cout << x;
			//如果有多個因數 要輸出次方
			if (t > 1) cout << "^" << t;
			//輸出完都要加 ＊ ,如果因數都找完了 n就會被除到剩下1 所以就不用加 ＊
			if (n != 1) cout << " * ";
		}
		x++;
	}
}