#include <bits/stdc++.h>
using namespace std;

int cnt[30];

int main()
{
    string s;
    while(cin >> s)
    {
        int a=-1,b=-1,c=-1;
        for(int i=0;i<s.size();++i)
        {
            if(s[i] == '/')
            {
                if(a == -1) a = i+1;
                else c = i+1;
            }
            else if(s[i] == '-') b = i+1;
        }
        if(b != -1)
        {
            a = stoi(s.substr(a, b-a));
            c = stoi(s.substr(c));
            // cout << a << " " << c << "\n";
        }
        else
        {
            a = stoi(s.substr(a));
            // cout << a << "\n";
        }
        if(b != -1)
        {
            for(int i=a;i<=c;++i) cnt[i-1]++;
        }
        else cnt[a]++;
    }
    cout << " Mon   Tue   Wed   Thu   Fri   Sat   Sun\n";
    for(int i=0;i<18;++i) cout << " ";
    for(int i=6;i<24;++i) cout << (to_string(i+1).size()==1 ? "0"+ to_string(i+1) : to_string(i+1)) << ":"  <<  (to_string(cnt[i]).size() == 1 ? "0" + to_string(cnt[i]) : to_string(cnt[i]))  << " \n"[(i+12)%7==0];
}
