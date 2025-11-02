#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    while(n--)
    {
        string s; cin >> s;
        int cnt = 0, ans = 0;
        for(int i=0;i<s.size();++i)
        {
            char c = s[i];
            if(c == '(') cnt++;
            else if(c == ')')
            {
                cnt--;
                ans++;
                if(cnt < 0) break;
            }
            // cout << "ans:" << ans << "\n";
        }
        if(cnt == 0) cout << ans << "\n";
        else cout << 0 << "\n";
    }
    return 0;
}

