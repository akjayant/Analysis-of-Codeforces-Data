#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

#define x first
#define y second
#define pb push_back
#define len(x) (int) x.size();
#define all(a) a.begin(), a.end()

#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define read(a) for (int i = 0; i < a.size(); ++i) cin >> a[i];
#define print(x, text) cout << text << " = " << x << endl;
#define printv(x, text) cout << text << " = "; for (auto e : x) cout << e << ' '; cout << endl;
#define printvp(x, text) cout << text << " =\n"; for (auto e : x) cout << e.first << ' ' << e.second << endl; cout << endl;

typedef long long ll;
//typedef vector <int> vi;
typedef vector <ll> vll;
//typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

int main() {
    fast_io;

    int n;
    cin >> n;

    vector <pll> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i].x >> a[i].y;
    }
    vll c(n), k(n);
    read(c); read(k);

    set <pll> u;
    for (int i = 0; i < n; ++i) {
        u.insert({c[i], i});
    }

    vector < set <pll> > min_r(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (i == j) continue;
            min_r[i].insert({(k[i] + k[j]) * (ll) (abs(a[i].x - a[j].x) + abs(a[i].y - a[j].y)), j});
        }
    }

    //printvp(u, "u");
    //for (auto e : min_r) {for (auto ee : e) {cout << ee.x << ' ';} cout << endl;} cout << endl;

    ll sum = 0;
    set <ll> el;
    set <ll> used;
    vector <pll> join;

    sum += (*(u.begin())).first;
    el.insert((*(u.begin())).second);
    used.insert((*(u.begin())).second);
    u.erase(u.begin());

    while (!u.empty()) {
        ll min_v = -1, min_u = -1, min_cost = 1e17;
        for (auto i : used) {
            //cout << "&" << i << endl;
            while (used.count((*(min_r[i].begin())).second) != 0) min_r[i].erase(min_r[i].begin());
            if (min_v == -1 || (*(min_r[i].begin())).first < min_cost) {
                min_v = (*(min_r[i].begin())).second;
                min_u = i;
                min_cost = (*(min_r[i].begin())).first;
            }
        }
        ll new_el = (*(u.begin())).second;
        ll new_el_cost = (*(u.begin())).first;

        /*print(min_v, "min_v");
        print(min_u, "min_u");
        print(min_cost, "min_cost");
        print(new_el, "new_el");
        print(new_el_cost, "new_el_cost");
        printvp(u, "u");
        printv(el, "el");
        cout << endl;*/

        if (new_el_cost < min_cost) {
            sum += new_el_cost;
            el.insert(new_el);
            used.insert(new_el);
            u.erase({c[new_el], new_el});
        }
        else {
            sum += min_cost;
            join.pb({min_u, min_v});
            used.insert(min_v);
            u.erase({c[min_v], min_v});
        }
        //cout << "#" << endl;
    }

    cout << sum << endl;
    cout << el.size() << endl;
    for (auto e : el) cout << e + 1 << ' '; cout << endl;
    cout << join.size() << endl;
    for (auto e : join) {
        cout << e.x + 1 << ' ' << e.y + 1 << endl;
    }
}
