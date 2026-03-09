vector<vector<int>> adj(V+1,vector<int>());
int diameter = 0;
function<int(int,int)> dfs = [&](int u, int p) -> int {
  int mxDepth1 = -1, mxDepth2 = -1;
  for(int v : adj[u]) {
    if( v == p ) continue;
    int depth = dfs( v, u );
    if( depth > mxDepth1 ) {
      mxDepth2 = mxDepth1;
      mxDepth1 = depth;
    }
    else if( depth > mxDepth2 )
      mxDepth2 = depth;
  }
  if( mxDepth1 != -1 and mxDepth2 != -1 )
    diameter = max(diameter,mxDepth1 + mxDepth2 + 2);
  if( mxDepth1 != -1 )
    diameter = max(diameter, mxDepth1 + 1);
  return mxDepth1 + 1;
};
dfs(1,0);
