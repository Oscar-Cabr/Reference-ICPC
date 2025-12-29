int V, E;
cin >> V >> E;
vvi edges(E,vi(3,0));

for(int i = 1; i <= E; i++)
  cin >> edges[i][0] >> edges[i][1] >> edges[i][2];

function<vi(int)> bellman_ford = [&](int src) -> vi
{
  vi dist(V,INF);
  dist[src] = 0;
  for(int i = 0; i < V; i++)
  {
     for( vi edge : edges )
     {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        if( dist[u] != INF and dist[u] + w < dist[v] )
        {
           if( i == V-1 )
              return = {-1};
           dist[v] = dist[u] + w;
        }
     }
  }
  return dist;
};
