#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n, x[maxn], y[maxn], a[maxn], k[maxn], f[maxn];
vector<pair<long long, int> > edges;

int getx(int id){
    if(id > n*n){
        return n+1;
    }
    return (id-1) / n + 1;
}

int gety(int id){
    if(id > n*n){
        return id - n*n;
    }
    return (id-1) % n + 1;
}

long long dis(int i, int j){
    return abs(x[i] - x[j]) + abs(y[i] - y[j]);
}

int find(int x){
    return f[x] == x ? x : f[x] = find(f[x]);
}

vector<pair<int, int> > ans_e;
vector<int> B;

int main()
{
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>x[i]>>y[i];
    }
    for(int i = 1; i <= n; i++) cin>>a[i];
    for(int i = 1; i <= n; i++) cin>>k[i];
    for(int i = 1; i <= n; i++){
        for(int j = i+1; j <= n; j++){
            edges.push_back(make_pair( (k[i] + k[j]) * dis(i, j), (i-1)*n+j ));
        }
    }
    for(int i = 1; i <= n; i++){
        edges.push_back(make_pair(a[i], n*n + i));
    }
    sort(edges.begin(), edges.end());
    for(int i = 1; i <= n+1; i++) f[i] = i;
    int m = 0;
    long long ans = 0;
    for(auto e : edges){
        int id = e.second;
        int x = getx(id), y = gety(id);
        if(x > y) swap(x, y);
        if(find(x) != find(y)){
            f[find(x)] = find(y);
            ans += e.first;
            if(y == n+1) B.push_back(x);
            else ans_e.push_back(make_pair(x, y));
            m++;
        }
        if(m == n) break;
    }
    cout<<ans<<endl;
    cout<<B.size()<<endl;
    for(auto b : B) cout<<b<<" "; cout<<endl;
    cout<<ans_e.size()<<endl;
    for(auto e : ans_e){
        cout<<e.first<<" "<<e.second<<endl;
    }
    return 0;
}
