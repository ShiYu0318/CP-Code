
#include<bits/stdc++.h>
using namespace std;
#define ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long

string str;
int pos = 0;
int compute();

int f()
{
    pos += 2;
    vector<int> args;
    while(1)
    {
        args.push_back(compute());
        if(str[pos] == ',')  pos++;
        else break;
    }
    pos++;
    return *max_element(args.begin(), args.end()) - *min_element(args.begin(), args.end());
}

int compute()
{
    vector<int> v_num;
    vector<char> v_sign;

    // 分類  1. 數字  2. +*   3. f()
    while(pos < str.size() && str[pos] != ')' && str[pos] != ',' )
    {
        int sum = 0;
        if('0' <= str[pos] && str[pos] <= '9')
        {
            while(pos < str.size() && '0' <= str[pos] && str[pos] <= '9')
            {
                sum = sum*10 + (str[pos]-'0');
                pos++;
            }
            v_num.push_back(sum);
        }
        else if(str[pos] == '+' || str[pos] == '*')
        {
            v_sign.push_back(str[pos]);
            pos++;
        }
        else if(str[pos] == 'f') v_num.push_back(f());
    }

    // 消掉 + 
    vector<int> temp;
    temp.push_back(v_num[0]);
    for(int i=0; i < v_sign.size(); ++i)
    {
        if(v_sign[i] == '*') temp.push_back(v_num[i+1]);
        else temp.back() += v_num[i+1];
    }

    // 剩下全部乘起來
    int ans = 1;
    for(int i=0; i < temp.size(); ++i) ans *= temp[i];
    return ans;
}

signed main()
{
    cin >> str;
    cout << compute() << "\n";
}