

//Q: -> Is Prime??
//code:
//-----
const int MAXN = 1e6 + 5;
vector<int> sieve(MAXN, true);
vector<int> Sieve() {
    sieve[0] = sieve[1] = false;
    for (int i = 2; i * i < MAXN; ++i) {
        if (sieve[i]){
            for (int j = i * i; j < MAXN; j += i){
                sieve[j] = false;
            }
        }
    }
    return sieve;
}
