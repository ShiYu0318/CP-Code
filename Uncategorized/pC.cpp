#include <bits/stdc++.h>
#define int long long
#define endl "\n"

using namespace std;

signed main(void) {

  ios_base::sync_with_stdio(0);
  cin.tie(0); 

  int s,e,a; //s 高度, e 顧客要求高度, a 耐性
  int day = 1;
  cin >> s >> e >> a;

  while(1) {
    if(a <= 0) {
      cout << "unsalable\n";
      break;
    }
    if(s < e) {
      day++;
      if(day % 3 == 1 && (day % 9 != 0 && day % 9 != 1)) { //休假隔天
        s += (s/3);
      } else if(day % 3 != 1 || (day % 9 != 0 && day % 9 != 1)){
        s += (s/10);
      } 
      if(day % 9 == 2) {
        if(e != s) a--;
        else if(e <= s){
          cout << day << endl;
          break;
        }
      }
    } else if (s >= e) {
      cout << day << endl;
      break;
    }
  }

  
}