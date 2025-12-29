void sum_of_divisors_sieve( vll& sigma, int n ) {
    sigma.assign(n+1,0);
    for(int i = 1; i <= n; i++)
        for(int j = i; j <= n; j+=i)
            sigma[j] += i;
}
