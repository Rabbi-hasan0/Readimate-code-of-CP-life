
-------------------------------------------------
// pre_build it is prime or not 
const int MAXN = 2e6 + 5;
vector<int> prime(MAXN, true);
vector<int> build_is_prime() {
    prime[0] = prime[1] = false;
    for (int i = 2; i * i < MAXN; ++i) {
        if (prime[i]){
            for (int j = i * i; j < MAXN; j += i){
                prime[j] = false;
            }
        }
    }
    return prime;
}

// Just check every step...
bool isprime(int n) {
    if (n < 2) return false;
    for(int i = 2; i <= (int)sqrt(n); i++){
        if (n % i == 0) return false;
    }
    return true;
}
------------------------------------------------------
