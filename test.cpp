#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, arr[1001];
    while(cin >> n) {
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        sort(arr, arr + n);
        for(int i = 0; i < n; i++) {
            cout <<  arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}