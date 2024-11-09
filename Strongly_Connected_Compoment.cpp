#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 3;
vector <int> g[N] , Tg[N];
int vis[N];
stack<int>st;
void dfs(int u) {
    vis[u] = true;
    for(auto it : g[u]) {
        if(!vis[it]) {
            dfs(it);
        }
    }
    st.push(u);
}
void dfs2(int u) {
    vis[u] = true;
    for(auto it : Tg[u]) {
        if(!vis[it]) {
            dfs2(it);
        }
    }
}
int main() {

   int node , edge;
   cin>>node>>edge;
   for(int i = 0; i < edge; i++) {
    int u , v;
    cin>>u>>v;
    g[u].push_back(v);
   }
   for(int i = 1; i<= node; i++) {
    if(!vis[i]) {
        dfs(i);
    }
   }
   for(int i = 1; i <= node; i++) {
       vis[i] = 0;
    for(auto it : g[i]) {
        Tg[it].push_back(i);
    }
   }
   int scc = 0;
   while(!st.empty()) {
    int node = st.top();
    st.pop();
      if(!vis[node]) {
            scc++;
        dfs2(node);
      }
   }
   cout<<scc<<endl;
    return 0;
}
