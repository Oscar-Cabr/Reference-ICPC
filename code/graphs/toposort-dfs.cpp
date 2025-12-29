vi topo;
vvi graph(V+1,vi());
vector<bool> visited(V+1,false);
function<void(int)> dfs = [&](int u) -> void {
   visited[u] = true;
   for(int v : graph[u])
      if( ! visited[v] )
         dfs(v);
   topo.pb(u);
};
function<void()> topological_sort = [&]() -> void {
   for(int i = 1; i <= V; i++)
      if( ! visited[i] )
         dfs(i);
   reverse(all(topo));
};
topological_sort();
for(int i = 0; i < V; i++) cout << topo[i] << " ";
