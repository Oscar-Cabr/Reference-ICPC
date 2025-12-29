vector<vector<int>> graph;
vector<bool> visited;
void dfs( int s ) {
    stack<int> stk;
    stk.push(s);
    while (!stk.empty()) {
        int u = stk.top();
        stk.pop();
        if ( visited[u] ) continue;
        visited[u] = true;
        // --- ToDo logic here ---
        for(auto it = graph[u].rbegin(); it != graph[u].rend(); ++it)
            if (!visited[*it])
                stk.push(*it);
    }
}
