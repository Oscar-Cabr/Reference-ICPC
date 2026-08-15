vi cnt(3,0), color(V+1,0);
function<void(int)> bfs = [&](int s) -> void {
  queue<int> q;
  bool bipartite = true;
  q.push(s);
  color[s] = 1;
  cnt[1]++;
  while( ! q.empty() ) {
    int u = q.front();
    q.pop();
    for(int v : adj[u]) {
      if( color[v] == 0 ) {
        color[v] = 3 - color[u];
        cnt[ color[v] ]++;
        q.push(v);
      }
      else if( color[v] == color[u] )
        bipartite = false;
    }
  }
  if(!bipartite) {
    cnt[1] = cnt[2] = 0;
  }
};
