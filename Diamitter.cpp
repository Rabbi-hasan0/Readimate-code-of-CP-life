#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
#define ll long long int
vector< pair< ll , ll > > g[N];
bool vis[N];
ll par[N];
ll dis[N];
ll indeg[N];
ll dis_of_S[N];
ll dis_of_E[N];
vector<int>v;
ll mx = INT_MIN;
ll node , ans;
void dfs1(ll u , ll p) {

    if(dis[u] > mx) {
        mx = dis[u];
        node = u;
    }
    for(auto [it , w] : g[u]) {
        if(it != p) {
        dis[it] = dis[u] + w;
            dfs1(it , u);
        }
    }
}
void dfs2(ll u , ll p) {
    if(dis[u] > mx) {
        mx = dis[u];
        node = u;
    }
    for(auto [it , w] : g[u]) {
        if(it != p) {
            dis[it] = dis[u] + w;
           dis_of_S[it] = dis_of_S[u] + w;
            dfs2(it, u);
        }
    }
}
void dfs3(ll u , ll p) {
    for(auto [it , w] : g[u]) {
        if(it != p) {
           dis_of_E[it] = dis_of_E[u] + w;
            dfs3(it, u);
        }
    }
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
            int n;
    cin>>n;
    for(int i = 1; i < n; i++) {
        int u , v , w;
        cin>>u>>v >> w;
        g[u].push_back({v , w});
        g[v].push_back({u , w});
    }
    dfs1(1 , 0);
    mx = 0;
    dis[node] = 0;
    dis_of_S[node] = 0;
    dfs2(node , 0);
    dis_of_E[node] = 0;
    dfs3(node , 0);
   for(int i = 1 ; i <= n; i++) {
    cout<<max(dis_of_S[i] , dis_of_E[i])<<" ";
   }
   cout<<endl;

    for(int i = 0; i <= n; i++) {
        g[i].clear();
        dis[i] = 0;
        mx = INT_MIN;
        ans = INT_MIN;
        dis_of_E[i] = 0;
        dis_of_S[i] = 0;
    }

    }
    return 0;
}
