#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

#define OK cin.tie(0);cout.tie(0);
#define LOL ios::sync_with_stdio(0);
typedef long long ll;

int main() {
  OK LOL
  
  int n, maxDis, maxHop;
  cin >> n >> maxDis >> maxHop;
  vector<pair<int, int>> a(n);
  for(auto &i : a) cin >> i.first >> i.second;

  vector<vector<int>> adj(n);
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      long long x = a[i].first - a[j].first;
      long long y = a[i].second - a[j].second;
      if (x*x+y*y <= 1LL*maxDis*maxDis) {
        adj[i].push_back(j);
        adj[j].push_back(i);
      }
    }
  }

  int q;
  cin >> q;
  while(q--) {
    int o, a, b;
    cin >> o >> a >> b;
    a--;b--;
    if(o == 1) {
      vector<int> dist(n, -1);
      queue<int> q;
      dist[a] = 0;
      q.push(a);
      while(!q.empty()) {
        int u = q.front();
        q.pop();
        if(dist[u] == maxHop) continue;
        for(auto i : adj[u]) {
          if(dist[i] == -1) {
            dist[i] = dist[u] + 1;
            q.push(i);
          }
        }
      }
      if(dist[b] != -1 && dist[b] <= maxHop) { 
        cout << "Yes " << dist[b] << '\n';
      } else {
        cout << "No" << '\n';
      }
    } else {
      vector<int> visited(n, 0);
      queue<int> q;
      visited[a] = 1;
      q.push(a);
      int oo = 0;
      bool found = false;
      while (!q.empty()) {
        int u = q.front(); q.pop();
        oo++;
        if (u == b) found = true;
        for (auto i : adj[u]) {
          if (!visited[i]) {
            visited[i] = 1;
            q.push(i);
          }
        }
      }
      if (found) {
        cout << "Yes " << oo << '\n';
      } else {
        cout << "No" << '\n';
      }
    }
  }
  return 0;
}