#include <bits/stdc++.h>

using namespace std;

#define MAXN 100005

int pre[MAXN];

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);


    string s1, s2;
    cin >> s1 >> s2;
    s1 = ' ' + s1;
    s2 = ' ' + s2;
    for (int i = 1; i < s2.size(); i++)
        pre[i] = pre[i - 1] + (s1[i] == s2[i]);

    int q;
    cin >> q;

    int l, r;
    while (q--) {
        cin >> l >> r;
        cout << (pre[r] - pre[l - 1] == (r - l + 1) ? "Really?!" : "I am so weak.") << '\n';
    }
}