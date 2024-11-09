#include <bits/stdc++.h>
using namespace std;
#define int long long int
class DisjointSet {
    vector<int> rank, parent;
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};
int32_t main() {

    int node , edges;
    cin>>node>>edges;
    DisjointSet se(node);
    vector<pair<int, pair<int , int>>> edge;
    for(int i = 1; i <= edges; i++) {
        int u , v ,w;
        cin>>u>>v>>w;
        edge.push_back({ w , {v , u}});
        edge.push_back({ w , {u , v }});

    }
    sort(edge.begin() , edge.end());
    int mstW = 0;
    for(auto it : edge) {
        int wt = it.first;
        int u = it.second.first;
        int v = it.second.second;

    if(se.findUPar(u) != se.findUPar(v)) {
          mstW += wt;
          se.unionByRank(u , v);
    }
    }
    cout<<mstW<<endl;


    return 0;
}
