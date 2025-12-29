vector<string> grid(n);
vii dirs = {{0,1},{0,-1},{1,0},{-1,0}};
ii start;
int arns = 0;
function<void(int,int)> traverse = [&](int i, int j) -> void {
  if( grid[i][j] == '#' ) return;
  int newI, newJ;
  if( grid[i][j] != '.' ) arns += grid[i][j] - '0';
  grid[i][j] = '#';
  for( ii move : dirs ) {
    newI = i + move.fi; newJ = j + move.se;
    if( newI >= 0 && newI < n && newJ >= 0 && newJ < m && grid[newI][newJ] == 'T' )
      return;
  }
  for( ii move : dirs ) {
    newI = i + move.fi; newJ = j + move.se;
    if( newI >= 0 && newI < n && newJ >= 0 && newJ < m )
      traverse(newI, newJ);
  }
};
fori(i,0,n)
  cin >> grid[i];
fori(i,0,n) {
  fori(j,0,m) {
    if( grid[i][j] == 'S' ) {
      grid[i][j] = '.';
      start.fi = i;
      start.se = j;
    }
  }
}
traverse(start.fi, start.se);
  cout << arns << endl;
