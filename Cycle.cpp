#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
vector<int> g[N];
int vis[N];
int col[N];
int cycle;
void dfs(int u) {
    col[u] = 1;
    for(auto v: g[u]) {
        if(!col[v]) {
            dfs(v);
        }
        else if(col[v] == 1) {
            cycle = true;
        }
    }
    col[u] = 2;
}
int main() {
    int n,m;
    cin>>n>>m;
    while(m--) {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);

    }
    cycle = false;
    for(int i = 1; i <= n; i++) {
        if(!col[i]) {
            dfs(i);
        }
    }
    if(cycle == true) {
        cout<<"YES"<<endl;
    }
    else {
        cout<<"NO"<<endl;
    }

}
