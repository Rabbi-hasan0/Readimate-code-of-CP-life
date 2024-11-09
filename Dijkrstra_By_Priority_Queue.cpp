
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 9;
const int inf = 1e18;
vector<pair<int, int>> g[N];
int node, edge;

void dijkstra(int u) {
    priority_queue<
        pair<int, int>,
        vector<pair<int, int>>,
        greater<pair<int, int>>
    > pq;

    vector<int> dist(node + 1, inf);
    vector<bool> visited(node + 1, false);
    int arr[node + 3];
    arr[1] = 1;
    dist[u] = 0;
    pq.push({0, u});

    while (!pq.empty()) {
        int dis = pq.top().first;
        int currentNode = pq.top().second;
        pq.pop();



        for (auto it : g[currentNode]) {
            int adjNode = it.first;
            int edgeWeight = it.second;

            if (dis + edgeWeight < dist[adjNode]) {
                dist[adjNode] = dis + edgeWeight;
                pq.push({dist[adjNode], adjNode});
                    arr[adjNode] = arr[currentNode];

            }
            else if(dis + edgeWeight == dist[currentNode]) {
                arr[adjNode] = arr[adjNode] + arr[currentNode];
            }
        }
    }

    for (int i = 1; i <= node; i++) {
        cout << dist[i] << " ";
    }
    cout << endl;
    cout<<"Number_of_Ways : "<<arr[node]<<endl;
}

int32_t main() {
    cin >> node >> edge;
    for (int i = 0; i < edge; i++) {
        int u, v, w;
        cin >> u >> v ;
        w = 1;
        g[u].push_back({v, w});
    }
    dijkstra(1);
}
