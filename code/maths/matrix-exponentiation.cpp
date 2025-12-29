template <typename T> void matmul(vector<vector<T>> &a, const vector<vector<T>>& b) {
   size_t n = a.size(), m = a[0].size(), p = b[0].size();
   assert(m == b.size());
   vector<vector<T>> c(n,vector<T>(p));
   for(size_t i = 0; i < n; i++)
      for(size_t j = 0; j < p; j++)
         for(size_t k = 0; k < m; k++)
            c[i][j] = (c[i][j] + a[i][k] * b[k][j]) % MOD;
   a = c;
}
template <typename T> struct Matrix {
   vector<vector<T>> mat;
   Matrix() {}
   Matrix(vector<vector<T>> a) { mat = a; }
   Matrix(int n, int m) {
      mat.resize(n);
      for(int i = 0; i < n; i++) {mat[i].resize(m); }
   }
   int rows() const { return mat.size(); }
   int cols() const { return mat[0].size(); }
   void makeIden() {
      for(int i = 0; i < rows(); i++)
         for(int j = 0; j < cols(); j++)
            mat[i][j] = (i == j ? 1 : 0);
   }
   Matrix operator*=(const Matrix &b) {
      matmul(mat, b.mat);
      return *this;
   }
   void print() {
      for(int i = 0; i < rows(); i++) {
         for(int j = 0; j < cols(); j++)
            cout << mat[i][j] << " ";
         cout << endl;
      }
   }
   Matrix operator*(const Matrix &b) { return Matrix(*this) *= b; }
};
int main() {
   Matrix<ll> A( {{1,1},{1,0}} );
   Matrix<ll> ini(2,1);
   ini.mat[0][0] = 0;
   ini.mat[1][0] = 1;
   Matrix<ll> iden(2,2);
   iden.makeIden();
   ll n;
   cin >> n;
   while(n > 0) {
      if( n & 1 ) iden *= A;
      A *= A;
      n >>= 1;
   }
   Matrix<ll> res = iden * ini;
   cout << res.mat[0][0] << endl;
   return 0;
}
