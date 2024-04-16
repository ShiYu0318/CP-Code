#include <bits/stdc++.h>
using namespace std;
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define int long long

// AC Yude 寫的

const ll md = 1e9+7;

int a,b,c,d,x1,x2,x3,x4;

bool duck(int num) {
    return (num == 2 || num == 3 || num == 9);
}

int calculate(int a, int b, int c, int d, int x1, int x2, int x3, int x4) {
    int sc=0;
	if (a % 2 == 0) sc += x1;
    if (duck(b) || duck(d)) sc += x2;
    if (duck((c + d) % 10)) sc += x3;
    if (duck((a + d) / 10)) sc += x4;
    return sc;
}

signed main(void)
{
    IO
    vector<int> nums(4);
    for (int i=0;i<4;i++)cin >> nums[i];
	cin >> x1 >> x2 >> x3 >> x4;
    sort(nums.begin(), nums.end());

    int mxsc=0;
    do {
        a = nums[0];
        b = nums[1];
        c = nums[2];
        d = nums[3];
        int sc = calculate(a, b, c, d, x1, x2, x3, x4);
        mxsc = max(mxsc,sc);
    } while (next_permutation(nums.begin(), nums.end()));


    cout << mxsc << endl;
}