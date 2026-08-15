// o = orientation of the turn p[i] -> p[i+1] -> p[i+2]:
// > 0 counter-clockwise, < 0 clockwise, == 0 collinear.
bool is_convex(const vector<pt>& p, bool allow_collinear = true) {
    int n = sz(p);
    if (n <= 2) return true;
    ll sgn = 0;
    fori(i, 0, n) {
        ll o = (p[(i+1)%n] - p[i]).cross(p[(i+2)%n] - p[i]);
        if (o == 0) {
            if (!allow_collinear) return false;
            continue;
        }
        if (sgn == 0) sgn = (o > 0 ? 1 : -1);
        else if (o * sgn < 0) return false;
    }
    return true;
}
