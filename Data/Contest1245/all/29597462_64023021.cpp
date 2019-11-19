#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
vi p,rk;
int n;
int x[2005], y[2005], c[2005], k[2005];
iii edgelist[5000005];
void init(int n){
    for (int i = 0; i < n; i++){
        p.push_back(i);
        rk.push_back(0);
    }
}
int findset(int x){
    return (p[x] == x) ? x : p[x] = findset(p[x]);
}
bool sameset(int i, int j){
    return findset(i) == findset(j);
}
void unionset(int x, int y){
    x = findset(x), y = findset(y);
    if (x == y) return;
    if (rk[x] < rk[y]){
        p[x] = y;
    }
    else{
        p[y] = x;
        if (rk[x] == rk[y]) rk[x]++;
    }
}
main(){
    scanf("%lld",&n);
    for (int i = 1; i <= n; i++){
        scanf("%lld%lld",&x[i],&y[i]);
    }
    for (int i = 1; i <= n; i++){
        scanf("%lld",&c[i]);
    }
    for (int i = 1; i <= n; i++){
        scanf("%lld",&k[i]);
    }
    int e = 0;
    for (int i = 1; i <= n; i++){
        edgelist[e++] = (iii(c[i],ii(0,i)));
        for (int j = 1 ;j < i; j++){
            int dist = max(x[i]-x[j],x[j]-x[i]) + max(y[i]-y[j],y[j]-y[i]);
            int cost = (k[i]+k[j])*dist;
            edgelist[e++] = (iii(cost,ii(j,i)));
        }
    }
    init(n+1);
    sort(edgelist,edgelist+e);
    int ans = 0;
    vector<int> ans1;
    vector<ii> ans2;
    int numtaken = 0;
    for (int i = 0; i < e; i++){
        int st = edgelist[i].second.first, en = edgelist[i].second.second, cost = edgelist[i].first;
        if (!sameset(st,en)){
            numtaken++;
            ans += cost;
            unionset(st,en);
            if (st == 0){
                ans1.push_back(en);
            }
            else{
                ans2.push_back(ii(st,en));
            }
        }
        if (numtaken == n) break;
    }
    printf("%lld\n",ans);
    printf("%lld\n",(int)ans1.size());
    for (int i = 0; i < (int)ans1.size(); i++){
        if (i) printf(" ");
        printf("%lld",ans1[i]);
    }
    printf("\n");
    printf("%lld\n",(int)ans2.size());
    for (auto x : ans2){
        printf("%lld %lld\n",x.first,x.second);
    }



}
