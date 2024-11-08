
//Q: Given which number are Prime? 
//code:
//-----
const int N = 1e5 + 7;
vector<long long> prime;
void sieve(int N){
    vector<bool> Prime(N + 1, true);
    for(int p = 2; p * p <= N; p++){
        if(Prime[p]) {
            for(int i = p * 2; i <= N; i += p){
                Prime[i] = false;
            }
        }
    }
    for(int p = 2; p <= N; p++){
        if (Prime[p]){
            prime.push_back(p);
        }
    }
}



