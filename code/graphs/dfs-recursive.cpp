vector<vector<int>> graph;
vector<bool> visited;
graph.assign(n, vector<int>() ); // <--- main
visited.assign(n, false); // <--- main

void dfs( int s ) {
    if( visited[s] == true ) return;
    visited[s] = true;
    vector<int>::iterator i;
    for( i = graph[s].begin(); i < graph[s].end(); ++i) {
        if( ! visited[*i] ) {
            // --- ToDo logic here ---
            dfs(*i);
        }
    }
}
