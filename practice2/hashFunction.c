
unsigned int hash(const char *s, const int n) {
    const unsigned int p = 37, m = 1e9 + 9;
    unsigned long long hash = 0;
    unsigned long long pow = 1;
    for (int i = 0; i < n; i++) {
        hash = (hash + (s[i] - 'a' + 1) * pow) % m;
        pow = (pow * p) % m;
    }
    return (unsigned int) hash;
}
