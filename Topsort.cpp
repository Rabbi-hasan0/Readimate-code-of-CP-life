#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
vector<int>g[N];
int vis[N];
int indeg[N];
int main() {
    int n,m;

    while(cin>>n>>m && n && m ) {
    while(m--) {
        int u,v;
        cin>>u>>v;
        indeg[v]++;
        g[u].push_back(v);
    }
    vector<int>z;
    for(int i = 1; i <= n; i++) {
        if(indeg[i] == 0) {
            z.push_back(i);
            vis[i] = true;
        }
    }
    vector<int>ans;
    while(ans.size() < n) {
     if(z.empty()) {
        cout<<"IMPOSSIBLE"<<endl;
        return 0;
     }
     int cur = z.back();
     z.pop_back();
     ans.push_back(cur);
     for(auto v: g[cur]) {
        indeg[v]--;
        if(!vis[v] && indeg[v] == 0) {
            z.push_back(v);
        }
     }
    }
     for(auto it: ans) {
        cout<<it<<" ";
     }
    }
}
