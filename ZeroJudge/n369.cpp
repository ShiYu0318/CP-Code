#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    string a,b;
    set<string> s;
    while(n--)
    {
        cin >> a >> b;
        if(s.count(a)) cout << b << " account has been used\n";
        else
        {
            cout << "welcome, " << b << "\n";
            s.insert(a);
        }
    }
}