#include <bits/stdc++.h>
using namespace std;

signed main()
{
    int a;
    while(cin >> a)
    {
        stack<int> s;
        int n = a;
        while(n > 4)
        {
            int t = n;
            while(t != 0)
            {
                s.emplace(t % 10);
                t /= 10;
            }
            n = 0;
            while(s.size() != 0)
            {
                n += s.top() * s.top();
                s.pop();
            }
        }
        cout << a << (n == 1 ? " is a happy number" : " is an unhappy number") << "\n";
    }
    return 0;
}