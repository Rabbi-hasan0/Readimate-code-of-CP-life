
template <class T>   // Complexity: O(n*log(n));
int cal_mex(vector<T> v) {
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  int n = int(v.size());
    for (int i = 0; i < n; ++i) {
        if (v[i] != i) {
            return i;
        }
    }
  return n;
}
