typedef array<int,3> iii;

vii dirs = {{1,0},{0,1},{-1,0},{0,-1}};
map<int,string> path = {{0,"D"},{1,"R"},{2,"U"},{3,"L"}};
int n, m;
string arns = "";
bool escaped = false;
cin >> n >> m;
vector<string> grid(n);
vvi times(n,vi(m,INF)), prev(n,vi(m,-1));
vector<vector<bool>> visited(n,vector<bool>(m,false));
queue<iii> q;
ii start, end;
for(int i = 0; i < n; i++) {
  cin >> grid[i];
  for(int j = 0; j < m; j++) {
    if( grid[i][j] == 'M' ) {
      q.push({i,j,0});
      times[i][j] = 0;
    }
    else if( grid[i][j] == 'A' )
      start = {i,j};
  }
}
function<bool(int,int)> valid = [&](int I, int J) -> bool {
  return (I >= 0) and (I < n) and (J >= 0 ) and (J < m) and (grid[I][J] != '#') and (times[I][J] == INF);
};
function<bool(int,int)> valid_player = [&](int I, int J) -> bool {
  return (I >= 0) and (I < n) and (J >= 0) and (J < m) and (!visited[I][J]) and (grid[I][J] != '#');
};
function<bool(int,int)> is_border = [&](int I, int J) -> bool {
  return I == 0 || I == n-1 || J == 0 || J == m-1;
};
// Corner cases 
if( is_border(start.fi,start.se) ) {
  cout << "YES" << endl << "0" << endl;
  return 0;
}
// Multi-Source BFS
while( ! q.empty() ) {
  iii u = q.front();
  q.pop();
  for(ii dir : dirs) {
    int newI = u[0] + dir.fi;
    int newJ = u[1] + dir.se;
    int w = u[2] + 1;
    if( valid(newI,newJ) ) {
      times[newI][newJ] = w;
      q.push({newI,newJ,w});
    }
  }
}
// Player BFS
q.push({start.fi,start.se,0});
visited[start.fi][start.se] = true;
while( ! q.empty() and !escaped ) {
  iii u = q.front();
  q.pop();
  for(int i = 0; i < 4; i++) {
    int newI = u[0] + dirs[i].fi;
    int newJ = u[1] + dirs[i].se;
    int w = u[2] + 1;
    if( valid_player(newI,newJ) and w < times[newI][newJ] ) {
      visited[newI][newJ] = true;
      prev[newI][newJ] = i;
      q.push({newI,newJ,w});
      if( is_border(newI,newJ) ) {
        end.fi = newI;
        end.se = newJ;
        escaped = true;
        break;
      }
    }
  }
}
if( !escaped ) {
  cout << "NO" << endl;
  return 0;
}
// Path reconstruction 
cout << "YES" << endl;
int i = end.fi;
int j = end.se;
while( prev[i][j] != -1 ) {
  int oldI = i;
  arns += path[ prev[i][j] ];
  i -= dirs[prev[i][j]].fi;
  j -= dirs[prev[oldI][j]].se;
}
reverse(all(arns));
cout << sz(arns) << endl << arns << endl;
