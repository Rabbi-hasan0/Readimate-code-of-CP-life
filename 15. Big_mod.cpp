int power(long long n, long long k, int mod) { // n^k % mod --> mod <= 10^9 [O(log(k))];
  int ans = 1 % mod; 
  n %= mod; 
  if (n < 0) n += mod;
  while (k) {
    if (k & 1) ans = (long long) ans * n % mod;
    n = (long long) n * n % mod;
    k >>= 1;
  }
  return ans;
}

using ull = unsigned long long
ull power(ull x, ull n) { // O(log n) --> x^n mod 2^64
  ull ans = 1;
  while (n > 0) {
    if (n & 1) ans *= x;
    x *= x; n >>= 1;
  }
  return ans;
}
