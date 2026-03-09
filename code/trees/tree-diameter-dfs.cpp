vector<vector<int>> adj(V+1,vector<int>());
int diameter = 0, fartest = 1;
function<void(int,int,int)> dfs = [&](int u, int p, int dist) -> void {
  if( dist > diameter ) {
    fartest = u;
    diameter = dist;
  }
  for( int v : adj[u] ) {
    if( v == p ) continue;
    dfs(v,u,dist+1);
  }
};
dfs(1,0,0);
diameter = 0;
dfs(fartest,0,0);
