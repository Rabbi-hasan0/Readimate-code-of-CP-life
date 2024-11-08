const int N = 3e5 + 9;
int a[N];
struct ST {
    int t[4 * N];
    static const int inf = 1e9;
    ST() {
        memset(t, 0, sizeof(t));
    }
    void build(int node, int b, int e) {
        if(b == e) {
            t[node] = a[b];
            return;
        }
        int mid = (b + e) >> 1, l = node << 1, r = l | 1;
        build(l, b, mid);
        build(r, mid + 1, e);
        t[node] = t[l] + t[r];
    }
    void update(int node, int b, int e, int i, int val) {
        // If i is out of range then return;
        if(i < b or e < i) {
            return;
        }
        // If satisfy my condition then update;
        if(b == e and i == b) {
            t[node] = val;
            return;
        } 
        int mid = (b + e) >> 1, l = node << 1, r = l | 1;
        update(l, b, mid, i, val);
        update(r, mid + 1, e, i, val);
        t[node] = t[l] + t[r];
    }
    int query(int node, int b, int e, int i, int j) { // here l, r is given as query 
        //check condition if node is totally outside;
        if(b > j or e < i) {
            return 0;
        }
        //check condition if node is totally inside;
        if(i <= b and e <= j) {
            return t[node];
        }
        int mid = (b + e) >> 1, l = node << 1, r = l | 1;
        return query(l, b, mid, i, j) + query(r, mid + 1, e, i, j);
    }

}st;   // Call [   st.function_name();   ];
