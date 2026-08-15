struct pt{
    ll x, y;
    pt(){}
    pt(ll _x, ll _y) : x(_x), y(_y){}
    pt operator +(const pt &p) const { return pt(x+p.x, y+p.y);}
    pt operator -(const pt &p) const { return pt(x-p.x, y-p.y);}
    bool operator == (pt const &t) const {
        return x == t.x && y == t.y;
    }
    bool operator < (pt const &p) const { return x < p.x || (x == p.x && y < p.y); }
    ll cross(const pt & p) const { return x*p.y - y*p.x;}
    ll dot(const pt &p) const { return x*p.x + y*p.y;}
    ll norm() const {return this-> dot(*this);}
};
