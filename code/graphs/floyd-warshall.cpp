vvll dist(n+1,vll(n+1,INF));
for(int i = 1; i <= n; i++)
  dist[i][i] = 0;
for(int i = 0; i < m; i++) {
  dist[u][v] = w;
  dist[v][u] = w;
}
function<void()> floyd_warshall = [&]() -> void {
  for(int k = 1; k <= n; k++)
    for(int i = 1; i <= n; i++)
      for(int j = 1; j <= n; j++)
        if( dist[i][k] < INF and dist[k][j] < INF )
          dist[i][j] = min( dist[i][j], dist[i][k] + dist[k][j] );
};
