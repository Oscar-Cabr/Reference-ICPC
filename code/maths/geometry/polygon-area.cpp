double polygon_area(const vector<pt>& p){
    ll area = 0;
    int n = p.size();
    fori(i,0,n){
        area += p[i].cross(p[(i+1) % n]);
    }
    return abs((double)area)/2;
}
