const int MAXN = 1e6+1;
vll fact(MAXN+1), inv(MAXN+1);
int binpow( ll a, ll b ) { // a^b
    ll sol = 1;
    a %= MOD;
    while( b > 0 ) {
        if( b & 1 )
            sol = ( 1LL * sol * a ) % MOD;
        a = ( 1LL * a * a ) % MOD;
        b >>= 1;
    }
    return sol % MOD;
}
void combi() {
    fact[0] = inv[0] = 1;
    fori(i,1,MAXN+1) {
        fact[i] = fact[i-1] * i % MOD;
        inv[i] = binpow( fact[i], MOD - 2 );
    }
}
ll nCr( ll n, ll r ) {
    return fact[n] * inv[r] % MOD * inv[n-r] % MOD;
}
combi();
nCr(a,b);
