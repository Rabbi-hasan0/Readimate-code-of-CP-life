
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
ll inf = 1e18;
const int N = 2e5+5;
vector< pair <ll , ll> > g[N];
vector<ll>dist(N , inf);
vector<ll> v;
int par[N];
    ll n , q;

void dijkstra(ll u ,ll p) {
    queue< pair<int , pair<int , int>> > q;
    vector<int>dist(n+ 1,1e18);
    dist[u] = 0;
    q.push({ 0 ,{ u , 0}});
    while(!q.empty()) {
           auto it = q.front();
           q.pop();
           int stops = it.first;
           int node = it.second.first;
           int cost = it.second.second;
           if(stops  > p) {
                    continue;
                }
           for(auto it : g[node]) {
               int New_Node = it.first;
               int edgW = it.second;
               if(cost + edgW < dist[New_Node] && stops <= p) {
                dist[New_Node] = cost + edgW;
                stops++;
                q.push({stops , {New_Node , dist[New_Node]} });
               }
           }
    }
}
int main() {
    cin>>n>>q;
    while(q--) {
        ll u , v , w;
        cin>>u>>v>>w;
        g[u].push_back({v , w});
    }
    int stops;
    cin>>stops;
    dijkstra(1 , stops);


}
