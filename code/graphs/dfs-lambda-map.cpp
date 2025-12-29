typedef long long ll;
typedef vector<ll> vll;
map<ll,vll> adj;
set<ll> visited;
function<void(ll)> dfs = [&](ll u) -> void {
    if( visited.count(u) ) return;
    visited.insert(u);
    for( ll v : adj[u] )
        dfs(v);
};
dfs(n);
