// Longest Prefix-Suffix
vi compute_LPS(string s) {
  size_t len = 0, i = 1, sz = s.size();
  vi lps(sz,0);
  while( i < sz ) {
    if( s[i] == s[len] )
      lps[i++] = ++len;
    else
      if( len != 0 )
        len = lps[len-1];
      else
        lps[i++] = 0;
  }
  return lps;
}
// Get number of occurrences of a pattern p in a string s
int kmp(string s, string p) {
  vi lps = compute_LPS(p);
  size_t n = s.size(), m = p.size(), i = 0, j = 0;
  int cnt = 0;
  while( i < n ) {
    if( p[j] == s[i] ) {
      j++; i++;
    }
    if( j == m ) { // Full match
      cnt++;
      j = lps[ j - 1];
    }
    else if( i < n and p[j] != s[i] ) { // Mismatch after j matches
      if( j != 0 )
        j = lps[ j - 1 ];
      else
        i++;
    }
  }
  return cnt;
}
