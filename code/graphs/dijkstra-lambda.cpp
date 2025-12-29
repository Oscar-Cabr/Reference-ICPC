vvpll graph(n+1,vpll());
vector<bool> visited(n+1,false);
function<vll(int)> dijkstra = [&](int source) -> vll {
   vll dist(n+1,INF);
   priority_queue<pll,vpll,greater<pll>> pq;
   dist[source] = 0;
   pq.push({0,source});
   while( ! pq.empty() ) {
      ll d = pq.top().fi;
      ll u = pq.top().se;
      pq.pop();
      if( d > dist[u] ) continue;
      for(pll edge : graph[u]) {
         ll v = edge.fi;
         ll w = edge.se;
         if( dist[u] + w < dist[v] ) {
            dist[v] = dist[u] + w;
            pq.push({dist[v],v});
         }
      }
   }
   return dist;
};
