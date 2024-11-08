

const int mod1 = 1e9 + 7, mod2 = 1e9 + 9;
const int p1 = 137, p2 = 277, N = 1e5 + 1;
int pw1[N], pw2[N];
void pre_cal_pw() {
    pw1[0] = 1;
    for(int i = 1; i < N; i++) {
        pw1[i] = (pw1[i - 1] * p1) % mod1;
    }
    pw2[0] = 1;
    for(int i = 1; i < N; i++) {
        pw2[i] = (pw2[i - 1] * p2) % mod2;
    }
}
pair<int, int> get_hash(string &s) {
    int res1 = 0, j = 0;
    for(auto &i: s) {
        res1 += ((i - 'a' + 1) * pw1[j++]) % mod1;
        res1 %= mod1;
    }
    int res2 = 0; j = 0;
    for(auto &i: s) {
        res2 += ((i - 'a' + 1) * pw2[j++]) % mod2;
        res2 %= mod2;
    }
    return {res1, res2};
}
