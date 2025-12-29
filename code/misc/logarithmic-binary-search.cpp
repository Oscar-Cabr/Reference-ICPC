int binary_search( vector<int>& list, int n, int target ) {
    int ans = 0;
    function<bool(int)> check = [&](int idx)->bool {
        return idx < n && list[idx] <= target;
    };
    for( int i = 31; i >= 0; i-- ) {
        if( check( ans + (1 << i) ) )
            ans += 1 << i;
    }
    return list[ans] == target ? ans : -1;
}
