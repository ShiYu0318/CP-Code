#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+5; // 宣告一個常數 N 作為陣列要開的空間，題目說（N<=10^6），保險起見多加個 5
int P[N]; // 先開好陣列所需的空間為 1000005

int main()
{
    int n; cin >> n;
    for(int i=0; i<n; i++) cin >> P[i];
    for(int i=n-1; i>=0; i--) cout << P[i] << ' '; // 反過來輸出，注意 index 範圍要寫對
    return 0;
}