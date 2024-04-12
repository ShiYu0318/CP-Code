// 建表 利用程式幫忙建
#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios::sync_with_stdio(0); cin.tie(0)
#define FORn(i,n) for(int i=0;i<n;++i)

const string tb[] = {"clank","bong","click","tap","poing","clonk","clack","ping",
                    "tip","cloing","tic","cling","bing","pong","clang","pang","clong",
                    "tac","boing","boink","cloink","rattle","clock","toc","clink","tuc"};

signed main()
{
    ShiYu;
    int n; cin >> n;
    // 利用程式幫忙建
    // string s;
    // while(n--)
    // {
    //     cin >> s;
    //     cout << "\"" + s + "\",";
    // }
    string s,ans;
    int capslock = 0;
    while(n--)
    {
        cin >> s;
        if(s == "whack") ans += ' ';
        else if(s == "pop" && !ans.empty()) ans.pop_back();
        else if(s == "bump" || s == "dink" || s == "thumb") capslock = 1 - capslock;
        else
        {
            FORn(i,26)
            {
                if(s == tb[i])
                {
                    if(capslock) ans += (char)('A' + i);
                    else ans += (char)('a' + i);
                }
            }
        }
    }
    cout << ans << "\n";
}