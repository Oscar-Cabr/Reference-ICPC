typedef long long ll;
vector<vector<ll>> adj;
vector<bool> visited;
function<void(ll)> dfs = [&](ll u) -> void {
    if( visited[u] ) return;
    visited[u] = true;
    for( ll v : adj[u] )
        dfs(v);
};
dfs(n);
