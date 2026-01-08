class DisjointSets {
private:
	vector<int> parents;
public:
	vector<int> sizes;
	DisjointSets(int size) : parents(size), sizes(size, 1) {
		for (int i = 0; i < size; i++) { parents[i] = i; }
	}
	/** @return the "representative" node in x's component */
	int find( int x ) {
	    return parents[x] == x ? x : ( parents[x] = find( parents[x] ) );
	}
	/** @return whether the merge changed connectivity */
	bool unite( int x, int y ) {
		int x_root = find(x);
		int y_root = find(y);
		if (x_root == y_root) return false;
		if ( sizes[x_root] < sizes[y_root] ) swap(x_root,y_root);
		sizes[x_root] += sizes[y_root];
		parents[y_root] = x_root;
		return true;
	}
	/** @return whether x and y are in the same connected component */
	bool connected( int x, int y ){
    return find(x) == find(y);
  }
	void printLists() {
	    cout << "Printing parents..." << endl;
	    for(auto i : parents)
	        cout << i << " ";
      cout << endl << "Printing sizes..." << endl;
      for(auto i : sizes )
          cout << i << " ";
	}
};
DisjointSets dsu( V );
int number_of_components = V, largest_component = 1;
if( dsu.unite(x, y) ) {
  largest_component = max( largest_component, dsu.sizes[ dsu.find( x ) ] );
  number_of_components--;
}
