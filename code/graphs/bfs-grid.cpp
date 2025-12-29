int n, m;
string arns = "";
cin >> n >> m;
vector<vector<bool>> visited(n,vector<bool>(m,false));
vector<string> path(n,string(m,'0'));
vector<string> grid(n);
vii dirs = {{0,1},{0,-1},{1,0},{-1,0}};
string commands = "LRUD";
queue<ii> q;
ii start, end, curr;
function<bool(int,int)> valid = [&](int i, int j) -> bool {
   return ( i >= 0 && i < n && j >= 0 && j < m && grid[i][j] != '#' && ! visited[i][j] );
};
fori(i,0,n) cin >> grid[i];
fori(i,0,n) {
   fori(j,0,m)
      if( grid[i][j] == 'A' ) {
         visited[i][j] = true;
         q.push( {i,j} );
      }
}
while( ! q.empty() ) {
   curr = q.front();
   q.pop();
   int i = curr.fi;
   int j = curr.se;
   if( grid[i][j] == 'B' ) {
      end.fi = i;
      end.se = j;
      break;
   } 
   int newI, newJ;
   fori(I,0,4) {
      newI = i + dirs[I].fi;
      newJ = j + dirs[I].se;
      if( valid(newI,newJ) ) {
         visited[newI][newJ] = true;
         q.push( {newI,newJ} );
         path[newI][newJ] = commands[I];
      }
   }
}
while( path[ end.fi ][ end.se ] != '0' ) {
   fori(i,0,4) {
      if( path[ end.fi ][ end.se ] == commands[i] ) {
         arns += i & 1 ? commands[i-1] : commands[i+1];
         end.fi -= dirs[i].fi;
         end.se -= dirs[i].se;
      }   
   }
}
reverse(all(arns));
if( arns == "" ) cout << "NO" << endl;
else cout << "YES" << endl << arns.size() << endl << arns << endl;
