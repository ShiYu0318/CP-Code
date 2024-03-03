#include <bits/stdc++.h>

using namespace std;

#define MAXN 2005

string s[MAXN];
int pos[MAXN];

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string input;
    int nowsize = 0;
    int leftcnt = 0;
    while (cin >> input) {
        s[nowsize++] = input;

        if (input == "]") {
            for (int i = nowsize - 1; i >= 0; i--) {
                if (s[i] == "[") {
                    for (int j = i + 1; j < (nowsize - 1) - (j - (i + 1)); j++) {
                        swap(s[j], s[(nowsize - 1) - (j - i)]);
                    }
                    for (int j = i; j < nowsize - 1; j++) {
                        swap(s[j], s[j + 1]);
                    }
                    nowsize -= 2;
                    break;
                }
            }
        }
    }

    for (int i = 0; i < nowsize; i++) {
        cout << s[i] << ' ';
    }                                               
    cout << endl;
}