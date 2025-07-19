#include <bits/stdc++.h>

using namespace std;

#define int long long
#define MAXN 400005

int n, k;
int a[MAXN];
int pre[MAXN];

int f(int l, int r) {
    return (l + r) * (r - l + 1) / 2;
}

signed main() {
    cin >> n >> k;

    int circle = k / n;
    int ans = 0;

    k %= n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ans += f(max(0LL, a[i] - circle + 1), a[i]);
        a[i] = max(0LL, a[i] - circle);
        a[i + n] = a[i];
    }
    for (int i = 1; i <= 2 * n; i++)
        pre[i] = pre[i - 1] + a[i];

    int mx = 0;
    for (int i = 1; i <= n; i++) {
        mx = max(mx, pre[i + k] - pre[i]);
    }
    cout << ans + mx << endl;
}