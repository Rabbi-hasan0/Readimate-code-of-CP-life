#include <bits/stdc++.h>
using namespace std;
#define int long long int
const int INF = LLONG_MAX;
const int N = 2e5 + 5;
vector<tuple<int, int, int>> edges;
vector<int> dist(N, INF);
int par[N];
bool Negative_Cycle = false;
int last_update = -1;
 int flag = true;

void bellmanFord(int n, int src) {
    dist[src] = 0;

    // Step 1: Relax all edges (n-1) times
    for (int i = 1; i <= n - 1; ++i) {
        for (auto edge : edges) {
            int u, v, w;
            tie(u, v, w) = edge;
            if (dist[u] != INF && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                par[v] = u;
            }
        }
    }

    // Step 2: Check for negative weight cycles
    for (auto edge : edges) {
        int u, v, w;
        tie(u, v, w) = edge;
        if (dist[u] != INF && dist[u] + w < dist[v]) {
            Negative_Cycle = true;
            last_update = v;
            par[v] = u;
            break;
        }
    }

    // Step 3: Print the negative cycle if it exists
    if (Negative_Cycle) {
        for (int i = 0; i < n; ++i) {
            last_update = par[last_update]; // Move n steps back to guarantee a cycle
        }

        vector<int> cycle;
        int start_cycle = last_update;
        cycle.push_back(start_cycle);
        int current = par[start_cycle];

        // Build the cycle by following parent links
        while (current != start_cycle) {
            cycle.push_back(current);
            current = par[current];
        }
        cycle.push_back(start_cycle); // Close the cycle
        reverse(cycle.begin(), cycle.end()); // Correct the order

        // Output the cycle
        cout << "YES\n";
        for (int node : cycle) {
            cout << node << " ";
        }
        cout << "\n";
        flag = false;

    }


}

int32_t main() {
    int n, q;
    cin >> n >> q;

    for (int i = 0; i < q; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        edges.push_back(make_tuple(u, v, w));
    }
      fill(par, par + n + 1, -1); // Initialize parents to -1
    for(int i = 1; i <= n; i++) {
        if(dist[i] == INF && flag) {
            bellmanFord(n , i);
        }
        else if(!flag) {
            break;
        }
    }
    if(flag) {
        cout<<"NO"<<endl;
    }


    return 0;
}
