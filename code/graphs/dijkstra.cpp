typedef long long ll;
typedef pair<ll,ll> pll;

vector<vector<ll>> graph;
vector<ll> visited;
graph.assign(n, vector<ll>() ); // <--- main
visited.assign(n, false); // <--- main

vector<ll> dijkstra( int n, int source, vector<vector<pll>> &graph ) {
  vector<ll> dist( n, INFTY );
  priority_queue<pll, vector<pll>, greater<pll>> pq;
  dist[ source ] = 0;
  pq.push( {0, source} );
  while( ! pq.empty() ) {
    ll d = pq.top().first;
    ll u = pq.top().second;
    pq.pop();
    if( d > dist[ u ] ) continue;
    for( auto &edge : graph[ u ] ) {
      ll v = edge.first;
      ll weight = edge.second;
      if( dist[ u ] + weight < dist[ v ] ) {
        dist[ v ] = dist[ u ] + weight;
        pq.push( {dist[ v ], v} );
      }
    }
  }
  return dist;
}
