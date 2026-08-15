const int MAXN = 1e6+1;
vll fact(MAXN+1), inv(MAXN+1);
int binpow( ll a, ll b ); // defined in binpow.cpp

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
