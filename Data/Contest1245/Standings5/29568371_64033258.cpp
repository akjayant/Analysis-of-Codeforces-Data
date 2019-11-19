#include <bits/stdc++.h>

using namespace std;

struct dst{
    long long a;
    int b, c;
};

bool cmp(dst a, dst b){
    return a.a < b.a;
}

const int N = 2e5 + 7;
int p[N], sz[N], pos[N];

vector < int > mn;

void build_set(int n){
    for(int i = 0; i < n; ++i){
        p[i] = i;
        sz[i] = 1;
        pos[i] = i;
    }
}

int find_set(int v){
    if(v == p[v]) return v;
    return p[v] = find_set(p[v]);
}

bool union_sets(int x, int y, long long val){
    x = find_set(x);
    y = find_set(y);
    if(val > max(mn[x], mn[y])){
        return false;
    }
    if(x != y){
        if(sz[x] > sz[y]){
            swap(x, y);
        }
        sz[y] += sz[x];
        sz[x] = 0;
        p[x] = y;
        if(mn[x] < mn[y]){
            mn[y] = mn[x];
            pos[y] = pos[x];
        }
        mn[x] = 0;
        return true;
    }
    else{
        return false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    cin >> n;

    int x[n], y[n];
    for(int i = 0; i < n; ++i){
        cin >> x[i] >> y[i];
    }

    int c[n];
    for(int i = 0; i < n; ++i){
        cin >> c[i];
        mn.push_back(c[i]);
    }

    int k[n];
    for(int i = 0; i < n; ++i){
        cin >> k[i];
    }

    build_set(n);

    vector < dst > s;
    for(int i = 0; i < n; ++i){
        for(int j = i + 1; j < n; ++j){
            long long dist = abs(x[i] - x[j]) + abs(y[i] - y[j]);
            long long val = dist * (k[i] + k[j]);
            s.push_back({val, i, j});
        }
    }

    vector < pair < int, int > > e;

    sort(s.begin(), s.end(), cmp);

    long long ans = 0;
    for(auto to : s){
        if(union_sets(to.c, to.b, to.a)){
            e.push_back({to.c, to.b});
            ans += to.a;
        }
    }

    vector < int > r;
    vector < bool > us(n); int cnt = 0;
    for(int i = 0; i < n; ++i){
        ans += mn[i];
        if(mn[i]){
            r.push_back(pos[i]);
            ++cnt;
        }
    }

    cout << ans << endl;
    cout << cnt << endl;
    for(int i = 0; i < r.size(); ++i){
        cout << r[i] + 1 << ' ';
    } cout << endl;
    cout << e.size() << endl;
    for(int i = 0; i < e.size(); ++i){
        cout << e[i].first + 1 << ' ' << e[i].second + 1 << endl;
    }
}
