

//Q: -> Is Prime??
//code:
//-----
bool isprime(int n) {
    if (n < 2) return false;
    for(int i = 2; i <= (int)sqrt(n); i++){
        if (n % i == 0) return false;
    }
    return true;
}


