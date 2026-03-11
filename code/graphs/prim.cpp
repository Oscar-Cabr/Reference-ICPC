function<ll()> prim = [&]() -> ll
{
  priority_queue<pll,vpll,greater<pll>> pq;
  ll res = 0;
  pq.push({0,1});
  while( ! pq.empty() )
  {
    pll p = pq.top();
    pq.pop();
    int w = p.fi;
    int u = p.se;
    if( visited[u] ) continue;
    res += w;
    visited[u] = true;
    for(pll v : graph[u])
      if( ! visited[v.fi] )
        pq.push({v.se,v.fi});
  }
  for(int i = 1; i <= V; i++)
    if( ! visited[i] )
      return -1;
  return res;
};
