#include <iostream>
#include <algorithm>
#include <set>
#include "vector"
#include "queue"
#include <math.h>

using namespace std;

vector<int64_t> c, k;

struct Edge {
    int from;
    int to;
    double w;

    Edge(int from = 0, int to = 0, double w = 0) : from(from), to(to), w(w) {}
};

struct Vertex {
    int x;
    int y;

    Vertex(int x, int y) : x(x), y(y) {}
};

vector<Vertex> points;
int64_t dist(int i, int j) {
    return (abs(points[i].x - points[j].x) + abs(points[i].y - points[j].y)) * (k[i] + k[j]);
}

const long long int cons = 5000000000000000010LL;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie();
    cout.precision(10);
    // freopen("even.in", "r", stdin);
    // freopen("even.out", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points.emplace_back(x, y);
    }

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        c.push_back(a);
    }

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        k.push_back(a);
    }

    points.emplace_back(0, 0);
    n++;
    c[n - 1] = INT32_MAX;

    vector<int64_t > d(static_cast<unsigned int>(n));
    vector<int> p(static_cast<unsigned int>(n));
    fill(d.begin(), d.end(), INT64_MAX);
    //d[n - 1] = Edge(0, 0, 0);
    d[n - 1] = 0;

    int64_t ans = 0;
    int w = n - 1;
    int newW = 0;
    vector<int> ansVer;
    vector<Edge> ansEdge;

    for (int i = 0; i < n - 1; i++) {
        double minEdge = INT64_MAX;

        for (int j = 0; j < n; j++) {
            int64_t distance;
            if (w == n - 1 || j == n - 1) {
                if (w == n - 1)
                    distance = c[j];
                else
                    distance = c[w];
            } else {
                distance = dist(w, j);
            }
            if (distance < d[j]) {
                d[j] = distance;
                p[j] = w;
            }
            if (d[j] != 0 && d[j] < minEdge) {
                minEdge = d[j];
                newW = j;
            }
        }

        if (p[newW] == n - 1) {
            ansVer.push_back(newW + 1);
        } else {
            ansEdge.emplace_back(p[newW] + 1, newW + 1, d[newW]);
        }

        ans += d[newW];
        w = newW;
    }

    cout << ans << "\n";
    cout << ansVer.size()<< "\n";
    for (int i : ansVer)
        cout << i << " ";
    cout << "\n";
    cout << ansEdge.size() << "\n";
    for (Edge& e : ansEdge)
        cout << e.from << " " << e.to << "\n";
}