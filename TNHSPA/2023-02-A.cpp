#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0);cin.tie(0);
/*
思路：
不想用條件慢慢判斷時分秒 所以直接把時間全部換成秒
相減後 考慮兩種相差方式(大-小 或 跨隔天)
找相差較小的那個 再從秒換算回來時分秒
*/
signed main(void)
{
	ShiYu;
	int ha,ma,sa,sumA; //資料A
	int hb,mb,sb,sumB; //資料B
	int x,y; //時間相差有可能是 x（大的時間-小的時間）或是 y（跨了半夜12點到隔天）
	int hc,mc,sc,sumC;
	cin >> ha >> ma >> sa >> hb >> mb >> sb;
	// 分別換算成秒
	sumA = (ha * 60 + ma) * 60 + sa;
	sumB = (hb * 60 + mb) * 60 + sb;
	x = abs(sumA - sumB); // (大的時間-小的時間)
	y = 24 * 60 * 60 - x; // (跨了半夜12點到隔天 也就是用24小時去減掉x)
	// 看看哪個相差比較小
	if(x < y) sumC = x;
	else if(x > y) sumC = y;
	else // 相差一樣代表沒差
	{
		cout << 0 << ' ' << 0 << ' ' << 0 << "\n";
		return 0; // 用到 early return 讓下方換算的事情不要做
	}
	// 把比較小的那個換算成時分秒
	sc =  sumC % 60;
	sumC /= 60;
	mc = sumC % 60;
	hc = sumC / 60;
	cout << hc << ' ' << mc << ' ' << sc << "\n";
	return 0;
}