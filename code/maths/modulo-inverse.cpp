const int MOD = 1e9+7;
int binpow( long long a, long long b ); // defined in binpow.cpp

int inv(int a) {
  return binpow(a, MOD-2);
}
