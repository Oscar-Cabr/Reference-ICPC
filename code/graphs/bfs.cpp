vector<vector<int>> graph;
vector<bool> visited;
graph.assign(n, vector<int>() ); // <--- main
visited.assign(n, false); // <--- main

void bfs( int s ) {
	queue<int> q;
	q.push( s );
	visited[ s ] = true;
	while( ! q.empty() ) {
		int u = q.front();
		q.pop();
		for( auto v : graph[ u ] ) {
			if( ! visited[ u ] ) {
				visited[ u ] = true;
				q.push( v );
				// --- ToDo logic here ---
			}
		}
	}
	return;
}
