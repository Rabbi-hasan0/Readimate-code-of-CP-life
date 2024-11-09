#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
vector<int> g[N];
bool vis[N]; int dis[N], par[N];

int32_t main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m; cin >> n >> m;
  while (m--) {
    int u, v; cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  queue<int> q;
  q.push(1); vis[1] = true; dis[1] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    for (auto v: g[u]) {
      if (!vis[v]) {
        q.push(v);
        par[v] = u;
        vis[v] = true;
      }
    }
  }
  if(!vis[n]) {
    cout<<"IMPOSSIBLE"<<endl;
  }
  else {
  int v = n;
  vector<int>vp;
  while (v != 1) {
      vp.push_back(v);
    v = par[v];
  }
  vp.push_back(1);
    cout<<vp.size()<<endl;
  reverse(vp.begin(),vp.end());
  for(int i = 0; i < vp.size(); i++) {
    cout<<vp[i]<<" ";
  }
  cout<<endl;
  }
}
