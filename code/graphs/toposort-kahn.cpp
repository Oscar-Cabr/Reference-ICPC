vi indegree(V+1,0);
vvi graph(V+1,vi());
vector<bool> visited(V+1,false);
fori(i,0,E) {
   graph[u].pb(v);
   indegree[v]++;
}
function<vi()> topological_sort = [&]() -> vi {
  vi order, deg = indegree; // copy
  queue<int> q;
  for(int i = 1; i <= V; i++)
    if( deg[i] == 0 )
      q.push(i);
  while( ! q.empty() ) {
    int u = q.front(); q.pop();
    order.pb(u);
    for(int v : graph[u]) {
      deg[v]--;
      if(deg[v] == 0)
        q.push(v);
    }
  }
  return order;
};
vi topo = topological_sort();
if( (int)(topo.size()) != V ) cout << "IMPOSSIBLE" << endl;
