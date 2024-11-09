#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 105;
int g[N][N];
const int inf = 1e18;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m , q;
   cin >> n >> m >> q;
   vector<vector<int , int >>cost;

  while (m--) {
    int u, v , w;
     cin >> u >> v >> w;
    cost[u][v] = w;
    cost[v][u] = w;
  }
  for(int i = 1; i <= n; i++) {
    for(int j = 1; j <= n; j++) {
        if(i == j) {
            cost[i][j] = 0;
        }
        else if(cost[i][j]) {
            cost[i][j] = cost[i][j];
        }
        else {
            cost[i][j] = inf;
        }
    }
  }
  for(int mid = 1; mid <= n; mid++) {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cost[i][j] = min(cost[i][j] , cost[i][mid] + cost[mid][j]);
        }
    }
  }
  while(q--) {
    int u , v;
    cin>>u>>v;
    if(cost[u][v] != inf) {
        cout<<cost[u][v]<<endl;
    }
    else {
        cout<<-1<<endl;
    }

  }



  return 0;
}
