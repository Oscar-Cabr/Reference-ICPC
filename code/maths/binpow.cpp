const int MOD = 1e9+7;
int binpow( long long a, long long b ) { // a^b
    long long sol = 1;
    a %= MOD;
    while( b > 0 ) {
        if( b & 1 )
            sol = ( 1LL * sol * a ) % MOD;
        a = ( 1LL * a * a ) % MOD;
        b >>= 1;
    }
    return sol % MOD;
}
