
int lcp(int i, int j, int x, int y) {
    int l = 1, r = min(j - i + 1, y - x + 1), ans = 0;
    while (l <= r) {
        int mid = l + r >> 1;
        if (get_hash(i, i + mid - 1) == get_hash(x, x + mid - 1)){
            ans = mid;
            l = mid + 1;
        } else{
            r = mid - 1;
        }
    }
    return ans;
}
