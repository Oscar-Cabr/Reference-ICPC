int timer = 0;
// Queries on subtree range [in,out)
function<void(int,int)> euler_tour = [&](int u, int p) -> void {
  in[u] = timer++;
  for(int v : adj[u])
  if( v != p )
    euler_tour(v,u);
  out[u] = timer;
};
euler_tour(1,0);
//===== Queries with Fenwick Tree
BIT<ll> bit(V);
for(int u = 1; u <= V; u++) bit.update(in[u]+1,v[u]);
// Update 'node' to 'val' (set operation)
bit.update(in[node]+1,val-v[node]);
v[node] = val;
// Query (ET is 0-idx, but BIT 1-idx)
cout << bit.query(in[node]+1,out[node]) << endl;
//===== Queries with Segment Tree
vll flat(V+1);
for(int i = 1; i <= V; i++)
  flat[ in[i] ] = v[i];
Segment_tree st(V);
st.build(flat,1,0,V-1);
st.update(1,in[node],0,V-1,val);
st.query(1,in[node],out[node]-1,0,V-1);
