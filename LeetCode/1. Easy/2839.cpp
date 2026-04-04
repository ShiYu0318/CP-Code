class Solution {
    // 20260403
public:
    bool canBeEqual(string s1, string s2) {
        string a = {s1[0], s1[2]};
        string b = {s2[0], s2[2]};
        string c = {s1[1], s1[3]};
        string d = {s2[1], s2[3]};
        if(a[0] > a[1]) swap(a[0], a[1]);
        if(b[0] > b[1]) swap(b[0], b[1]);
        if(c[0] > c[1]) swap(c[0], c[1]);
        if(d[0] > d[1]) swap(d[0], d[1]);
        return a == b && c == d;
    }
};

// class Solution {
//     // 20260403
//     // 函式化
// public:
//     bool check(string &s1, string &s2, int a, int b)
//     {
//         return (s1[a] == s2[a] && s1[b] == s2[b]) || (s1[a] == s2[b] && s1[b] == s2[a]);
//     }
//     bool canBeEqual(string s1, string s2) {
//         return check(s1, s2, 0, 2) && check(s1, s2, 1, 3);
//     }
// };