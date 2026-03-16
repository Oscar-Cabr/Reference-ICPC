vvi adj(V+1,vi()), condensed, components;
vector<bool> visited;
function<void(int,const vvi&,vi&)> dfs = [&](int u, vvi const& g, vi& output) -> void {
  visited[u] = true;
  for(int v : g[u])
    if( ! visited[v] )
      dfs(v,g,output);
  output.push_back(u);
};
function<void()> kosaraju = [&]() -> void {
  vvi adj_t(V+1);
  vi order, roots(V+1,0);
  visited.assign(V+1,false);
  condensed.assign(V+1,vi());
  for(int v = 1; v <= V; v++)
    for(int u : adj[v])
      adj_t[u].push_back(v);
  for(int i = 1; i < V; i++)
    if( !visited[i] )
      dfs(i,adj,order);
  visited.assign(V+1,false);
  reverse(order.begin(), order.end());
  for(int v : order) {
    if( !visited[v] ) {
      vi component;
      dfs(v,adj_t,component);
      components.push_back(component);
      int root = *component.begin();
      for(int u : component)
        roots[u] = root;
    }
  }
  for(int v = 0; v < V; v++)
    for(int u : adj[v])
      if( roots[u] != roots[v] )
        condensed[ roots[v] ].push_back( roots[u] );
};
kosaraju();
