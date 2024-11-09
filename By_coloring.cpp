#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
vector<int> g[N];
int vis[N];
int color[N];
bool ok;
void dfs(int u) {
    vis[u] = true;

    for(auto it: g[u]) {
        if(!vis[it]) {
            color[it] = color[u] ^ 1;
            dfs(it);
        }
        else {
            if(color[u] == color[it]) {
            ok = false;

           }
        }
    }
}

int main() {

    int n;
    cin>>n;
   int t = n;
       while(t--) {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
       }


    ok = true;
    color[1] = true;
    dfs(1);
    if(ok){
        cout<<"BICOLORABLE."<<endl;
    }
    else{
        cout<<"NOT BICOLORABLE."<<endl;
    }
    for(int i = 1; i <= n; i++) {
        vis[i] = 0;
        g[i].clear();
        color[i] = 0;
    }



   }

