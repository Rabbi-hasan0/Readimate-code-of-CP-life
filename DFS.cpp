#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
bool vis[N];
vector<int>g[N];
void dfs(int u) {
     vis[u] = true;
     for(auto it: g[u]) {
        if(!vis[it]) {
            cout<<it<<" ";
            dfs(it);
        }
     }


}
int main() {
    int n,m;
    cin>>n>>m;
    map<int,int>mp;
    while(m--) {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1);
    for(int i = 1; i <= n; i++) {
        if(vis[i] != true) {
            cout<<"Disconnected Graph"<<endl;
            return  0;
        }
    }
    cout<<"Connected Graph"<<endl;
}

