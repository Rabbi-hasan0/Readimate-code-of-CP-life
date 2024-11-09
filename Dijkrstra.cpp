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

void dijkstra(ll u) {
    set< pair<ll , ll > > st;
    dist[u] = 0;
    st.insert({ 0 , u});
    while(!st.empty()) {
        auto it = *(st.begin());
        ll node = it.second;
        ll dis = it.first;
        st.erase(it);
        for(auto it : g[node]) {
            ll adjNode = it.first;
            ll edgW = it.second;
            if(dis + edgW < dist[adjNode]) {
                if(dist[adjNode] != inf) {
                    st.erase({dist[adjNode] , adjNode});
                    par[adjNode] = 0;
                }
                par[adjNode] = node;

                dist[adjNode] = dis + edgW;
                st.insert({dist[adjNode] , adjNode});
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        cout<<dist[i]<<" ";
    }
    cout<<endl;
    int p = n;
    cout<<"Path : ";
    while(p != 1) {
        v.push_back(p);
        p = par[p];
    }
    v.push_back(p);
    reverse(v.begin() , v.end());
    for(int i = 0; i < v.size(); i++)  {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
int main() {
    cin>>n>>q;
    while(q--) {
        ll u , v , w;
        cin>>u>>v>>w;
        g[u].push_back({v , w});
        g[v].push_back({ u , w});
    }
    dijkstra(1);


}
