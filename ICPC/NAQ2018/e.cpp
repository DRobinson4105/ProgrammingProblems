#include <bits/stdc++.h>
using namespace std;

typedef pair<double, double> pdd;

template<class T> struct Point {
    typedef Point P;
    T x, y;
    explicit Point(T x=0, T y=0) : x(x), y(y) {}
    bool operator<(P p) const { return tie(x, y) < tie(p.x, p.y); }
    bool operator==(P p) const { return tie(x, y) == tie(p.x, p.y); }
    P operator+(P p) const { return P{x+p.x, y+p.y}; }
    P operator-(P p) const { return P(x-p.x, y-p.y); }
    P operator*(T d) const { return P(x * d, y * d); }
    P operator/(T d) const { return P(x / d, y / d); }
    T dot(P p) const { return x * p.x + y * p.y; }
    T cross(P p) const { return x * p.y - y * p.x; }
    T cross(P a, P b) const { return (a-*this).cross(b-*this); }
    T dist2() const { return x * x + y * y; }
    double dist() const { return sqrt((double)dist2()); }
    double angle() const { return atan2(y, x); }
    P unit() const { return *this / dist(); }
    P perp() const { return P(-y, x); }
    P normal() const { return perp().unit(); }
    P rotate(double a) const {
        return P(x + cos(a) - y * sin(a), x * sin(a) + y * cos(a));
    }
    friend ostream& operator<<(ostream& os, P p) {
        return os << "(" << p.x << "," << p.y << ")";
    }
};

typedef Point<double> P;
vector<pair<P, P>> tangents(P c1, double r1, P c2, double r2) {
    P d = c2 - c1;
    double dr = r1 - r2, d2 = d.dist2(), h2 = d2 - dr * dr;
    if(d2 == 0 || h2 < 0) return {};
    vector<pair<P, P>> out;
    for(double sign : {-1, 1}) {
        P v = (d * dr + d.perp() * sqrt(h2) * sign) / d2;
        out.push_back({c1 + v * r1, c2 + v * r2});
    }
    if (h2 == 0) out.pop_back();
    return out;
}

bool circleLineIntersects(P c, double r, P a, P b) {
    P ab = b - a, p = a + ab * (c - a).dot(ab) / ab.dist2();
    double s = a.cross(b, c), h2 = r * r - s * s / ab.dist2();
    return h2 > 0 || abs(h2) <= 1e-6;
}

int main() {
    int n; cin >> n;
    vector<P> fruits(n);
    int best = 1;

    for (int i = 0; i < n; i++) {
        int count = 1;
        cin >> fruits[i].x >> fruits[i].y;

        for (int j = 0; j < i; j++)
            if (fruits[i] == fruits[j]) count++;
        
        best = max(best, count);
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            for (auto [a, b] : tangents(fruits[i], 1, fruits[j], 1)) {
                int count = 0;
                for (int k = 0; k < n; k++) {
                    count += circleLineIntersects(fruits[k], 1, a, b);
                }
                best = max(best, count);
            }
        }
    }

    cout << best << endl;
    return 0;
}
