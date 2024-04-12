#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define rFOR(i,n) for(int i=n-1;i>=0;--i)
#define RPT(i,n) FOR(i,0,n)
#define input(x) for(auto &i : x) cin >> i
#define output(x) for(auto i : x) cout << i << ' '
#define Yn(x) cout << (x ? "Yes" : "No") << '\n';
#define all(x) x.begin(),x.end()
#define int long long
#define F first
#define S second

// 自訂排序

string tb[8] = {"elder","nursy","kit","warrior","appentice","medicent","deputy","leader"};

struct st
{
    int type;
    int age;
    string name;
}arr[1000005];

bool cmp(const st a, st b)
{
    if(a.type != b.type) return a.type < b.type;
    if(a.age != b.age)
    {
        if(a.type == 5) return a.age < b.age;
        return a.age > b.age;
    }
    return a.name < b.name;
}

signed main()
{
    ShiYu;
    int n,m; 
    while(cin >> n >> m)
    {
        string name,type;
        int age;
        RPT(j,n)
        {
            cin >> name >> type >> age;
            RPT(i,8)
            {
                if(type == tb[i])
                {
                    arr[j].type = i+1;
                    arr[j].age = age;
                    arr[j].name = name;
                    break;
                }
            }
        }
        sort(arr,arr + n,cmp);
        RPT(i,min(n,m))
        {
            cout << arr[i].name << '\n';
        }
    }
}