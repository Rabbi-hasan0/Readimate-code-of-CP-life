#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> adj[N];
map<pair<int, int>, bool> used;  // To mark edges as used
vector<int> circuit;
int degree[N];

void findEulerianCircuit(int u) {
    stack<int> st;
    st.push(u);
    while (!st.empty()) {
        int v = st.top();
        bool found = false;

        while (!adj[v].empty()) {
            int next = adj[v].back();
            adj[v].pop_back();
            if (!used[{v, next}]) {
                used[{v, next}] = used[{next, v}] = true;
                st.push(next);
                found = true;
                break;
            }
        }

        if (!found) {
            circuit.push_back(v);
            st.pop();
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
        degree[a]++;
        degree[b]++;
    }

    // Check if all vertices with edges have even degree
    for (int i = 1; i <= n; i++) {
        if (degree[i] % 2 != 0) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }

    // Check connectivity for vertices with non-zero degree
    vector<bool> visited(n + 1, false);
    function<void(int)> dfs = [&](int u) {
        visited[u] = true;
        for (int v : adj[u]) {
            if (!visited[v]) dfs(v);
        }
    };
    int start = 1;
    dfs(start);

    for (int i = 1; i <= n; i++) {
        if (degree[i] > 0 && !visited[i]) {
            cout << "IMPOSSIBLE\n";
            return 0;
        }
    }

    // Find Eulerian Circuit starting from the post office (node 1)
    findEulerianCircuit(1);

    if (circuit.size() != m + 1) {
        cout << "IMPOSSIBLE\n";
    } else {
        reverse(circuit.begin(), circuit.end());
        for (int v : circuit) {
            cout << v << " ";
        }
        cout << "\n";
    }

    return 0;
}

