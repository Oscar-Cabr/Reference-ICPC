int binary_search( vector<int>& list, int n, int target ) {
    int x0 = 0, x1 = n-1, mid;
    while( x0 <= x1 ) {
        mid = (x0 + x1) / 2; // (x1 - x0) / 2 + x0;
        if( list[mid] == target )
            return mid;
        list[mid] < target ? x0 = mid + 1 : x1 = mid - 1;
    }
    return -1;
}
