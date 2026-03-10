template<typename T = long long>
struct BIT {
  int n;
  vector<T> tree;
  BIT(int n) : n(n), tree(n+1,0) {}
  BIT(vector<T> const &v) : BIT( v.size() ) {
    for(size_t i = 0; i < v.size(); i++)
      update(i+1,v[i]);
  }
  void update(int idx, T val) {
    while( idx <= n ) {
      tree[idx] += val;
      idx += idx & -idx;
    }
  }
  T prefix(int idx) const {
    T pref = 0;
    while( idx > 0 ) {
      pref += tree[idx];
      idx -= idx & -idx;
    }
    return pref;
  }
  T query(int l, int r) const {
    return prefix(r) - prefix(l-1);
  }
};
