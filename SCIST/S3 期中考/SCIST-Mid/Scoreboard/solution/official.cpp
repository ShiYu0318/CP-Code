#include <bits/stdc++.h>

using namespace std;

#define MAXN 105

int n, m, p;
string name[MAXN];
int score[MAXN][MAXN];

void print() {
    for (int i = 0; i < n; i++) {
        cout << name[i] << ' ';
        for (int j = 0; j < p; j++) {
            cout << (score[i][j] > 0 ? "+" + to_string(score[i][j] - 1) : to_string(score[i][j])) << ' ';
        }
        cout << '\n';
    }
}

void update(string user, int p, string res) {
    --p;
    for (int i = 0; i < n; i++) {
        if (name[i] == user) {
            if (res == "AC" && score[i][p] <= 0) {
                score[i][p] = abs(score[i][p]) + 1;
            }
            else if (score[i][p] <= 0) {
                score[i][p] -= 1;
            }
            break;
        }
    }
}

signed main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m >> p;

    for (int i = 0; i < n; i++)
        cin >> name[i];
    
    string op, res;
    int p;
    while (m--) {
        cin >> op;

        if (op == "view") {
            print();
        }
        else {
            cin >> p >> res;
            update(op, p, res);
        }
    }
} 