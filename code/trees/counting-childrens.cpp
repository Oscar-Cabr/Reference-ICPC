vi childrens(n+1,0);
vvi graph(n+1);
vector<bool> visited(n+1, false);
fori(i,2,n+1) {
   cin >> tmp;
   graph[tmp].pb(i);
   graph[i].pb(tmp);
}
function<int(int)> dfs = [&](int u) -> int { 
   visited[u] = true;
   for(int v : graph[u]) {
      if( !visited[v] )
         childrens[u] += dfs(v);
   }
   return childrens[u] + 1;
};
dfs(1);
