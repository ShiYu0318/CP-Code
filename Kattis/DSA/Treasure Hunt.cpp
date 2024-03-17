#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0),cin.tie(0);
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define rFOR(i,n) for(int i=n-1;i>=0;--i)
#define RPT(i,n) FOR(i,0,n)
#define input(x) for(auto &i : x) cin >> i
#define output(x) for(auto i : x) cout << i << " "
#define Yn(x) cout << (x ? "Yes" : "No") << "\n"
#define all(x) x.begin(),x.end()
// #define int long long
#define pii pair<int,int>
#define F first
#define S second

// 模擬 or 建表

int main()
{
    ShiYu
    int r,c; cin >> r >> c;
    int x=0,y=0,ans=0;
    vector<string> v(r); input(v);
    while(v[x][y] != 'T')
    {
        if(ans > r * c + 1)
        {
            cout << "Lost\n";
            return 0;
        }
        ++ans;
        bool find = false;
        switch (v[x][y])
        {
            case 'E':
                ++y;
                break;
            case 'W':
                --y;
                break;
            case 'N':
                --x;
                break;
            case 'S':
                ++x;
                break;
            case 'T':
                find = true;
                break;
        }
        if(find) break;
        if(!(0 <= x && x < r && 0 <= y && y < c))
        {
            cout << "Out\n";
            return 0;
        }
    }
    cout << ans << "\n";
}

// int r,c;

// map<char,pii> move_map = {
//     {'E',{0,1}},
//     {'W',{0,-1}},
//     {'N',{-1,0}},
//     {'S',{1,0}}
// };

// bool in_range(int x,int y)
// {
//     return (0 <= x && x < r) && (0 <= y && y < c);
// }

// int main()
// {
//     ShiYu
//     cin >> r >> c;
//     int x=0,y=0,ans=0;
//     vector<string> v(r); input(v);
//     while(v[x][y] != 'T')
//     {
//         if(ans > r * c * 2)
//         {
//             cout << "Lost\n";
//             return 0;
//         }
//         int mx = move_map[v[x][y]].F;
//         int my = move_map[v[x][y]].S;
//         if(in_range(x+mx,y+my))
//         {
//             x += mx;
//             y += my;
//             ++ans;
//         }
//         else
//         {
//             cout << "Out\n";
//             return 0;
//         }
//     }
//     cout << ans << "\n";
// }