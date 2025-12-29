function<bool(ll)> check = [&](ll t) -> bool {
  ll products = 0;
  for(ll machine : v) {
    products += t / machine;
    if( products >= target )
      return true;
  }
  return products >= target;
};
for(int i = 0; i < 70; i++) {
  mid = (x0 + x1) / 2;
  check(mid) ? x1 = mid : x0 = mid + 1;
}
