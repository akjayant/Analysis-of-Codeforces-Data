#include <bits/stdc++.h>
using namespace std;

struct point {
    long long x, y;
    point() {
        x = 0;
        y = 0;
    }
    point(long long x, long long y) : x(x), y(y) {}
};

long long dist(point a, point b) {
    return abs(a.x - b.x) + abs(a.y - b.y);
}

int n;
vector<point> city;
vector<long long> k;
vector<long long> c;
int a, b;
set<pair<long long, pair<int, int> > > d;
vector<int> starts;
vector<pair<int, int> > used;
map<int, pair<long long, pair<int, int> > > otobr;


pair<long long, pair<int, int> >  findmin() {
    return *d.begin();
}


int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        city.push_back({a, b});
    }
    k.resize(n);
    c.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        d.insert({c[i], {i, -1} });
        otobr[i] = {c[i], {i, -1} };
    }

    for (int i = 0; i < n; i++) {
        cin >> k[i];
    }
    long long answer = 0;
    for (int i = 0; i < n; i++) {
        auto a = findmin();
        answer += a.first;
        d.erase(a);
        if (a.second.second == -1) {
            starts.push_back(a.second.first);
        } else {
            used.push_back({a.second.first, a.second.second});
        }
        for (int j = 0; j < n; j++) {
            if (d.count(otobr[j]) == 1) {
                d.erase(otobr[j]);
                if (otobr[j].first > dist(city[j], city[a.second.first]) * (k[j] + k[a.second.first])) {
                    otobr[j] = {dist(city[j], city[a.second.first]) * (k[j] + k[a.second.first]), {j, a.second.first}};
                }
                d.insert(otobr[j]);
            }
        }
    }
    cout << answer << endl;
    cout << starts.size() << endl;
    for (int i = 0; i < starts.size(); i++) {
        cout << starts[i] + 1 << " ";
    }
    cout << endl;
    cout << used.size() << endl;
    for (int i = 0; i < used.size(); i++) {
        cout << used[i].first + 1 << " " << used[i].second + 1 << endl;
    }
    return 0;
}