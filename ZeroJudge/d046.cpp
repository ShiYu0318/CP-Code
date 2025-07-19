#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    int w, ans = 0;
    while (n--) 
    {
        cin >> w;
        if (w <= 10) ans++;
    }
    cout << ans << '\n';
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// int w[105];

// int main()
// {
//     int n; cin >> n;
//     int ans = 0;
//     for(int i=0; i<n; i++) cin >> w[i];
//     for(int i=0; i<n; i++)
//     {
//         if (w[i] <= 10) ans++;
//     }
//     cout << ans << '\n';
//     return 0;
// }