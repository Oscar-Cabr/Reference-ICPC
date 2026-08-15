int binary_search( vector<int>& list, int n, int target ) {
    int ans = 0;
    function<bool(int)> check = [&](int idx)->bool {
        return idx < n && list[idx] <= target;
    };
    if( list.empty() ) return -1;
    for( int i = 30; i >= 0; i-- ) { // 30 covers any n <= 2^31-1 without overflowing int
        if( check( ans + (1 << i) ) )
            ans += 1 << i;
    }
    return list[ans] == target ? ans : -1;
}
