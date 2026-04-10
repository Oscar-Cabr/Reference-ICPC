struct Point {
    ll x, y;

    Point operator-(const Point& other) const { //Resta de puntos (sobreescritura del operador "-")
        return {x - other.x, y - other.y};
    }

    ll cross(const Point& other) const {
        return x * other.y - y * other.x;
    }
};