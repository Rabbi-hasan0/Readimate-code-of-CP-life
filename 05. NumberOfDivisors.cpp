
// count how many divisor are the number
int numberOfDivisors(int n) { //complexity: O(sqrt(n) * log(n))
    int total = 1;
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            int e = 0;
            do {
                e++;
                n /= i;
            } while (n % i == 0);
            total *= e + 1;
        }
    }
    if (n > 1) {
        total *= 2;
    }
    return total;
}
