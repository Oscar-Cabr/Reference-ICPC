int binary_search( vector<int>& list, int n, int target ) {
  int  left = 1, right = n + 1, mid;
  while(right - left >= 1) {
    mid = left + (right - left) / 2;
    if( list[mid] >= target && target > list[mid - 1]) {
      //--------- TODO logic here ---------//
      break;
    }
    else 
      if( list[mid] < target )
        left = mid + 1;
      else
        right = mid;
  }
}
