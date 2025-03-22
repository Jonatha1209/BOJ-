#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> par; // parent[i][k] : i의 2^k번째의 부모
vector<int> dep; // 트리의 정점 깊이
vector<vector<int>> vec; // 그래프

// dfs로 트리 제작후 배열 채우기
void dfs(int x) {
  for (auto nxt : vec[x]) {
    if (dep[nxt] == -1) {
      par[nxt][0] = x;
      dep[nxt] = dep[x] + 1;
      dfs(nxt);  
    }
  }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    
    par.resize(n, vector<int>(20, -1)); 
    dep.resize(n, -1);
    vec.resize(n);

    for (int i = 0; i < n - 1; i++) {
      int a, b;
      cin >> a >> b;
      a--;
      b--;
      vec[a].push_back(b);   
      vec[b].push_back(a);
    }

    dep[0] = 0;
    dfs(0);
    
    for (int i = 0; i < 19; i++) {  // Log2(101010) is roughly 17, so we can use 19
      for (int j = 0; j < n; j++) {
        if (par[j][i] != -1) {
          par[j][i + 1] = par[par[j][i]][i];
        }
      }
    }

    int m;
    cin >> m;

    for (int i = 0; i < m; i++) {
      int a, b;
      cin >> a >> b;

      a--;
      b--;

      if (dep[a] < dep[b]) swap(a, b);

      int diff = dep[a] - dep[b];

      for (int j = 19; j >= 0; j--) {
        if (diff & (1 << j)) {
          a = par[a][j];
        }
      }

      if (a != b) {
        for (int j = 19; j >= 0; j--) {
          if (par[a][j] != par[b][j]) {
            a = par[a][j];
            b = par[b][j];
          }
        }
        a = par[a][0];
      }

      cout << a + 1 << "\n";
    }

    return 0;
}
