// https://zerojudge.tw/ShowProblem?problemid=a003
#include <iostream>
using namespace std;

int main()
{
	int M,D,S;
	cin >> M >> D;
	S = (M * 2 + D) % 3;
	if(S == 0){
		cout << "普通\n";
	} else if (S == 1){
		cout << "吉\n";
	} else {
		cout << "大吉\n";
	}
	return 0;
}
