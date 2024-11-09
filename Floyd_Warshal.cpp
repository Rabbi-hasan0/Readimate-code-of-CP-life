
#include<bits/stdc++.h>
using namespace std;
#define int long long int
const int N = 505;
int g[N][N];
const int inf = 1e18;
int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m , q;
   cin >> n >> m >> q;
    int cost[N][N];
for(int i = 1; i <= 501; i++) {
    for(int j = 1; j <= 501; j++) {
        if(i == j) {
            cost[i][j] = 0;
        }
        else {
            cost[i][j] = inf;
        }
    }
  }
  while (m--) {
    int u, v , w;
     cin >> u >> v >> w;
    cost[u][v] = min(cost[u][v] ,w);
    cost[v][u] = min(cost[u][v] , w );
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
    if(cost[u][v] < 0) {
        cout<<"Neagtive Cycle"<<endl;
    }
    else {
        cout<<-1<<endl;
    }

  }



  return 0;
}
