const int N = 1e5 + 9;
int a[N + 1];
struct ST {
  #define lc (n << 1)   //define rig
  #define rc ((n << 1) + 1)
  int t[4 * N], lazy[4 * N];
  static const int inf = 1e9;
  ST() {
    memset(t, 0, sizeof(t));
    memset(lazy, 0, sizeof(lazy));
  }
  inline void pull(int n) {
    t[n] = t[lc] + t[rc];
  }
  inline int combine(int a,int b) { 
    return a + b;
  }
  inline void push(int n, int b, int e) {
    if(lazy[n] == 0) return;
    t[n] = t[n] + lazy[n] * (e - b + 1);
    if(b != e) {
      lazy[lc] = lazy[lc] + lazy[n];
      lazy[rc] = lazy[rc] + lazy[n];
    }
    lazy[n] = 0;
  }
  void build(int n, int b, int e) { // Ekhan theke n jacce macro lc and rc te😁😁😁
    lazy[n] = 0;
    if (b == e) {
      t[n] = a[b];
      return;
    }
    int mid = (b + e) >> 1;
    build(lc, b, mid);
    build(rc, mid + 1, e);
    pull(n);
  }

  void update(int n, int b, int e, int i, int j, int val) {
    push(n, b, e);
    if(j < b || e < i) {
      return;
    }
    if(i <= b && e <= j) {
      lazy[n] = val;
      push(n, b, e);
      return;
    }
    int mid = (b + e) >> 1;
    update(lc, b, mid, i, j, val);
    update(rc, mid + 1, e, i, j, val);
    pull(n);
  }

  int query(int n, int b, int e, int i, int j) {
    push(n, b, e);
    if(j < b || e < i) {
      return 0;
    }
    if(i <= b && e <= j) {
      return t[n];
    }
    int mid = (b + e) >> 1;
    return combine(query(lc, b, mid, i, j), query(rc, mid + 1, e, i, j));
  }
}st;
