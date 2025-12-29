ll sum_of_divisors(ll n) {
  ll sum = 1;
  for (long long i = 2; i * i <= n; i++) {
    if(n % i == 0) {
      int e = 0;
      do {
        e++;
        n /= i;
      } while (n % i == 0);
      ll s = 0, pow = 1;
      do {
        s += pow;
        pow *= i;
      } while (e-- > 0);
      sum *= s;
    }
  }
  if(n > 1)
    sum *= (1 + n);
  return sum;
}
