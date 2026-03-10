template<typename T = long long>
struct BIT2D {
  int n, m;
  vector<vector<T>> tree;
  BIT2D(int n, int m) : n(n), m(m), tree(n+1,vector<T>(m+1,0)) {}
  BIT2D(vector<vector<T>> const &mat) : BIT2D(mat.size(), mat[0].size()) {
    for(int i = 0; i < n; i++)
      for(int j = 0; j < m; j++)
        update(i+1,j+1,mat[i][j]);
  }
  void update(int x, int y, T val) const {
    while( x <= n ) {
      int j = y;
      while( j <= m ) {
        tree[x][y] += val;
        j += j & -j;
      }
      x += x & -x;
    }
  }
  T prefix(int x, int y) const {
    T pref = 0;
    while( x > 0 ) {
      int j = y;
      while( j > 0 ) {
        pref += tree[x][y];
        j -= j & -j;
      }
      x -= x & -x;
    }
    return pref;
  }
  T query(int x1, int y1, int x2, int y2) const {
    return prefix(x2,y2) - prefix(x1-1,y2) - prefix(x2,y1-1) + prefix(x1-1,y1-1);
  }
};
