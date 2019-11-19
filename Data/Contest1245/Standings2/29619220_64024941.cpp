#include <bits/stdc++.h>
#define x first
#define y second
#define int long long

using namespace std;
int p[2000];
int r[2000];
bool e[2000];

int get(int u){
    if (p[u] == u) return u;
    return p[u] = get(p[u]);
}

bool join(int u, int v){
    u = get(u);
    v = get(v);
    if (u != v){
        if (r[u] > r[v]){
            if(e[v])
                e[u] = 1;
            p[v] = u;
            r[u] = max(r[u], r[v] + 1);
        }else{
            if(e[u])
                e[v] = 1;
            p[u] = v;
            r[v] = max(r[v], r[u] + 1);
        }
        return true;
    }
    return false;
}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    pair<int, int> ps[n];
    int el[n], c[n];
    for(int i = 0; i<n; i++){
        cin >> ps[i].x >> ps[i].y;
        p[i] = i;
        r[i] = 1;
        e[i] = 0;
    }
    vector<pair<int, pair<int, int>>> all;
    for(int i = 0; i<n; i++){
        cin >> el[i];
        all.emplace_back(el[i], make_pair(i, -1));
    }
    for(int i = 0; i<n; i++){
        cin >> c[i];
    }
    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            all.emplace_back((abs(ps[i].x-ps[j].x)+abs(ps[i].y-ps[j].y))*(c[i]+c[j]), make_pair(i, j));
        }
    }
    sort(all.begin(), all.end());
    int dd = 0;
    int res = 0;
    vector<int> fire;
    vector<pair<int, int>> conn;
    int in = 0;
    while(dd<n){
        pair<int, pair<int, int>> v = all[in];
        if(v.y.y==-1 && e[get(v.y.x)]){
            in++;
            continue;
        }
        if(v.y.y!=-1 && get(v.y.x) == get(v.y.y)){
            in++;
            continue;
        }
        if(v.y.y!=-1 && e[get(v.y.x)] && e[get(v.y.y)]){
            in++;
            continue;
        }
        if(v.y.y == -1){
            e[get(v.y.x)] = 1;
            fire.push_back(v.y.x);
            res+=v.x;
            dd++;
        } else {
            res+=v.x;
            join(v.y.x, v.y.y);
            conn.emplace_back(v.y.x, v.y.y);
            dd++;
        }
    }
    cout << res << "\n";
    cout << fire.size() << "\n";
    for(auto z:fire)
        cout << z+1 << " ";
    cout << "\n";
    cout << conn.size() << "\n";
    for(auto z:conn)
        cout << z.x+1 << " " << z.y+1 << "\n";
    return 0;
}
