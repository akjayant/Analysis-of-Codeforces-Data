#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5+7;
const ll mod = 1e9 + 7;
#define afdafafafdafaf y1;
int ar[maxn], n, m;
struct node{
    int x, y;
    ll val;
    node(int a = 0, int b = 0, ll c = 0){
        x = a;
        y = b;
        val = c;
    }
    bool operator < (const node& n1)const{
        return val > n1.val || (val == n1.val && x > n1.x) || (val == n1.val && x == n1.x && y > n1.y);
    }
};
priority_queue<node> qu;
int x_l[maxn], y_l[maxn], c[maxn], k[maxn];
int f[maxn], mark[maxn];
int findx(int x){
    return x == f[x] ? x : f[x] = findx(f[x]);
}
int main()
{
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        f[i] = i;
        mark[i] = 0;
    }
    for(int i=1;i<=n;i++){
        scanf("%d%d", x_l + i, y_l + i);
    }
    for(int i=1;i<=n;i++)scanf("%d", c+i);
    for(int i=1;i<=n;i++)scanf("%d", k+i);
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            ll val = 1LL * (k[i] + k[j]) * (abs(x_l[i] - x_l[j]) + abs(y_l[i] - y_l[j]));
            qu.push(node(i, j, val));
        }
    }
    for(int i=1;i<=n;i++){
        qu.push(node(i, -1, c[i]));
    }
    ll ans = 0, ins = 0;
    vector<int> ans1;
    vector<pair<int, int> > ans2;
    while(!qu.empty()){
        int a = qu.top().x, b = qu.top().y;
        ll val = qu.top().val;
        qu.pop();
        if(b == -1){
            int x = findx(a);
            if(mark[x]);
            else{
                mark[x] = 1;
                ans += val;
                ans1.push_back(a);
                ins++;
            }
        }
        else{
            int x = findx(a);
            int y = findx(b);
            if(x != y && mark[x] + mark[y] < 2){
                f[x] = y;
                if(mark[x] == 1)mark[y] = 1;
                ans += val;
                ans2.push_back(make_pair(a, b));
                ins++;
            }
        }
        if(ins == n)break;
    }
    assert(ins == n);
    printf("%lld\n", ans);
    printf("%d\n", int(ans1.size()));
    for(int i=0;i<ans1.size();i++){
        printf("%d%c", ans1[i], i == ans1.size() - 1 ? '\n' : ' ');
    }
    printf("%d\n", int(ans2.size()));
    for(int i=0;i<ans2.size();i++){
        printf("%d %d\n", ans2[i].first, ans2[i].second);
    }
    return 0;
}
