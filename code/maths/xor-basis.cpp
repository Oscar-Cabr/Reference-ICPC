template<typename T = int, int B = 31>
struct Basis {
  T basis[B];
  int bsz = 0;
  void clear() {
    memset(basis, 0, sizeof basis);
    bsz = 0;
  }
  Basis() {
    clear();
  }
  bool insert(T x) {
    for(int bit = B-1; bit >= 0; bit--) {
      if( x & (1 << bit) ) {
        if( basis[bit] )
          x ^= basis[bit];
        else {
          basis[bit] = x;
          bsz++;
          return true;
        }
      }
    }
    return false;
  }
  T max() {
    int mx = 0;
    for(int bit = B-1; bit >= 0; bit--)
      mx = std::max(mx,mx ^ basis[bit]);
    return mx;
  }
  bool can(T x) {
    for(int bit = B-1; bit >= 0; bit--)
      x = min(x,x ^ basis[bit]);
    return x == 0;
  }
  bool merge(Basis& b) {
    bool f = false;
    for(int bit = B-1; bit >= 0; bit--)
      if( b.basis[bit] and ! insert(b.basis[bit]) )
        f = true;
    return f;
  }
  T kth(int k) {
    T x = 0;
    T cnt = ((T)1 << bsz);
    for(int i = B-1; i >= 0; i--) {
      if(! basis[i] )
        continue;
      if( k > (cnt >> 1) ) {
        if( ! (x >> i & 1) )
          x ^= basis[i];
        k -= cnt >> 1;
      }
      else
        if( x >> i & 1 )
          x ^= basis[i];
      cnt >>= 1;
    }
    return x;
  }
};
