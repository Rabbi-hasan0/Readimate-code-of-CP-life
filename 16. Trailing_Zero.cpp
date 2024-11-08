int findZeros(int n){ // [O(logn)];
    int i = 5, cnt = 0;
    while (n / i) {
        cnt += n / i;
        i *= 5;
    }
    return cnt;
}
