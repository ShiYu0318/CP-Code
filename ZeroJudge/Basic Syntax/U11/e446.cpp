#include <bits/stdc++.h>
using namespace std;
#define ShiYu ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define rFOR(i,n) for(int i=n-1;i>=0;--i)
#define RPT(i,n) FOR(i,0,n)
#define input(x) for(auto &i : x) cin >> i
#define output(x) for(auto &i : x) cout << i << ' '
#define Yn(x) cout << (x ? "Yes" : "No") << "\n";
#define all(x) x.begin(),x.end()
#define int long long

// 全排列 iota do-while 
// puts 才會過

void print_permutations(int n) {
    // 生成1到N的數字序列
    vector<int> numbers;
    for (int i = 1; i <= n; ++i) {
        numbers.push_back(i);
    }

    // 使用std::next_permutation生成全排列並輸出
    do {
        // 將每種情況存成char陣列
        char output[3 * n];  // 考慮數字和空格
        int index = 0;
        for (int i = 0; i < n; ++i) {
            index += sprintf(output + index, "%d ", numbers[i]);
        }
        output[index - 1] = '\0';  // 刪除最後的空格，並添加字符串結尾符

        // 使用puts輸出
        puts(output);
    } while (next_permutation(numbers.begin(), numbers.end()));
}

signed main()
{
    ShiYu;
    int n; cin >> n;
    print_permutations(n);
}