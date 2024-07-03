#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define input(x) for(auto &i : x) cin >> i
#define output(x) for(auto &i : x) cout << i << ' '

int binary_search(int l, int r, int k, int arr[])
{
    int find = 0;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (arr[m] < k)
        {
            l = m + 1;
            find = m;
        }
        else r = m - 1;
    }
    return find;
}


signed main()
{
    ShiYu
    int n; cin >> n;
    int s[n]; input(s);
    sort(s, s+n); output(s);
    int ans = binary_search(0, n - 1, 60 , s);
    if (s[n - 1] < 60) cout << "\n" << s[ans] << "\nworst case\n";
    else if (s[0] >= 60) cout << "\nbest case\n" << s[ans] << "\n";
    else cout << "\n" << s[ans] << "\n" << s[ans+1] << "\n";
}