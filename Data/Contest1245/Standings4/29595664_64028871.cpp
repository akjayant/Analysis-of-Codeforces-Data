#include <bits/stdc++.h>

using namespace std;

#define REP(i,a,b) for(int i = a; i < b; i++)
#define DB( x ) cout << #x << " = " << x << endl;
#define sz(s) ((int)((s).size()))
#define endl '\n'

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, pii> tri;
typedef vector <vector <ll>> matrix;
typedef pair<string, string> pss;

const ll mod = (ll)1e9 + 7;
const int MAX = 100001;

const int oo = 0x3f3f3f3f;

vector<tri> edges;

int main() {

    ios_base :: sync_with_stdio(0); cin.tie(0);

    int n; cin >> n;

    vector<pii> v(n);

    map<pii, int> mmap;

    int index = 1;

    for(auto &it : v){
        cin >> it.first >> it.second;
        mmap[it] = index++;
    }

    vector<ll> cost(n), r(n);

    for(auto &it : cost)
        cin >> it;
    for(auto &it : r)
        cin >> it;

    for(int i = 0;i < n;++i){
        for(int j = i + 1;j < n;++j){
            ll tmp = abs(v[i].first - v[j].first) + abs(v[i].second - v[j].second);
            edges.push_back({tmp * (r[i] + r[j]), {mmap[v[i]], mmap[v[j]]}});
        }
        for(int j = 0;j < n;++j){
            ll tmp = abs(v[i].first - v[j].first) + abs(v[i].second - v[j].second);
            edges.push_back({tmp + cost[i], {mmap[v[i]], index}});
        }
    }

    vector<int> R(index + 100), P(index + 100);

    for(int i = 0;i < index + 100;++i)
        R[P[i] = i] = 1;

    function<int(int) > SetOf = [&](int x){
        if(P[x] == x)
            return x;
        else{
            P[x] = SetOf(P[x]);
            return P[x];
        }
    };

    function<bool(int, int) > Merge = [&](int x, int y){
        int xx = SetOf(x);
        int yy = SetOf(y);

        if(xx == yy)
            return false;
        if(R[x] < R[y])
            swap(xx, yy);
        R[xx] += R[yy];
        P[yy] = xx;
        return true;
    };

    sort(edges.begin(), edges.end());

    ll solve = 0, ps = 0;

    vector<int> cities;

    vector<pii> conections;

    for(auto it : edges){
        int x = it.second.first, y = it.second.second;
        if(Merge(x, y)) {
            solve += it.first;
            if(x == index || y == index) {
                ++ps;
                if(x == index)
                    cities.push_back(y);
                if(y == index)
                    cities.push_back(x);
            }
            else{
                conections.push_back({x, y});
            }
        }
    }

    cout << solve << endl;
    cout << ps << endl;
    for(auto it : cities) cout << it << " \n"[it == cities.back()];
    cout << sz(conections) << endl;
    for(auto it : conections)
        cout << it.first << " " << it.second << endl;
}