#include <bits/stdc++.h>

using namespace std;

#define MAXN 200005

#define int long long

int n, x;
char c;
char s[MAXN];
int cnt[MAXN];

void print(int l, int r) {
    int sum = cnt[l];
    char ch = s[l];

    for (int i = l + 1; i < r; i++) {
        if (s[i] == ch)
            sum += cnt[i];
        else {
            cout << sum << ch;
            sum = cnt[i];
            ch = s[i];
        }
    }

    cout << sum << ch << '\n';
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    int l = n, r = n, op;
    while (n--) {
        cin >> op;
        if (op == 5)
            print(l, r);

        if (op == 1) {
            cin >> x >> c;
            s[r] = c;
            cnt[r++] = x;
        }
        if (op == 2) {
            cin >> x >> c;
            s[--l] = c;
            cnt[l] = x;
        }
        if (op == 3) {
            cin >> x;
            int sum = 0;
            for (int i = r - 1; i >= l; i--) {
                sum += cnt[i];
                if (sum >= x) {
                    if (sum == x) {
                        r = i;
                        break;
                    }
                    else {
                        cnt[i] -= x - (sum - cnt[i]);
                        r = i + 1;
                        break;
                    }
                }
            }
        }

        if (op == 4) {
            cin >> x;
            int sum = 0;
            for (int i = l; i < r; i++) {
                sum += cnt[i];
                if (sum >= x) {
                    if (sum == x) {
                        l = i + 1;
                        break;
                    }
                    else {
                        cnt[i] -= x - (sum - cnt[i]);
                        l = i;
                        break;
                    }
                }
            }
        }
    }
}