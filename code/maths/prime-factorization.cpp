void prime_factorization(vll& factorization, ll n) {
    for(long long d = 2; d*d <= n; d++) {
        while(n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
    }
    if( n > 1 )
        factorization.push_back(n);
}
