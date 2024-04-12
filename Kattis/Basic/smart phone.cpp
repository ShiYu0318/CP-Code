#include <bits/stdc++.h>
using namespace std;
// 思路：分別求出四個字串要成為目標字串需多少步驟存入陣列 再找最小值
// 步驟算法：(字串長度-字串與目標字串相同的長度)+(目標字串長度-字串與目標字串相同的長度)
// 注意：除了自己寫的那個字串 剩下三個可替換的字串 步驟數都要加1
signed main()
{
	int n;
	cin >> n;
	while(n--)
	{
		int i,j,len,same,tlen,max=0,t,ts[4];
		string s[5];
		for(i=0;i<5;i++) cin >> s[i];
		len = s[0].size();
		
		for(i=1;i<5;i++)
		{
			same = 0;
			tlen = s[i].size();
			for(j=0;j<tlen;j++)
			{
				if(s[i][j] == s[0][j]) same++;
				else break;
			}
			
			t = (tlen - same) + (len - same);
			if(i>1) t++;
			ts[i-1] = t;
		}
		max = ts[0];
		for(i=1;i<4;i++)
		{
			if(ts[i] < max) max = ts[i];
		}
		cout << max << '\n';
	}
}