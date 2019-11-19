#include<bits/stdc++.h>
using namespace std;

#define repi(i, a, b) for(int i = (int)a; i <= (int)b; i++)
#define repd(i, a, b) for(int i = (int)a; i >= (int)b; i--)
#define _end printf("\n")
#define dg(x) cout << #x << '=' << x << ' '
#define mem(a, b) memset(a, b, sizeof(a))

void _in(long long *a, ...){

    va_list arg_ptr;

    scanf("%I64d", a);
    long long *temp;

    va_start(arg_ptr, a);
    temp = va_arg(arg_ptr, long long*);

    while(temp){
        scanf("%I64d", temp);
        temp = va_arg(arg_ptr, long long*);
    }

    va_end(arg_ptr);
}

void _in(int *a, ...){
    va_list arg_ptr;

    scanf("%d", a);
    int *temp;

    va_start(arg_ptr, a);
    temp = va_arg(arg_ptr, int*);
    while(temp){
        scanf("%d", temp);
        temp = va_arg(arg_ptr, int*);
    }

    va_end(arg_ptr);
}

#define in(...) _in(__VA_ARGS__, 0)
typedef long long ll;

const ll N = 2e3 + 100;

vector<ll> G[N];
ll x[N], y[N], c[N], k[N], n, fa[N];
vector<int> choo;

struct edge{
    ll s, t, d;
    edge(ll s = 0, ll t = 0, ll d = 0):s(s), t(t), d(d){}
};

vector<edge> E;

ll labs(ll v){
    return v < 0? -v : v;
}

ll dist(ll a, ll b){
    return (labs(x[a] - x[b]) + labs(y[a] - y[b])) * (k[a] + k[b]);
}

bool cmp(const edge &a, const edge &b){
    return a.d < b.d;
}

ll getfa(int a){
    if(fa[a] == a) return a;
    else{
        fa[a] = getfa(fa[a]);
        return fa[a];
    }
}

int main(){

    in(&n);
    repi(i, 1, n){
        in(&x[i], &y[i]);
    }
    repi(i, 1, n) in(&c[i]);
    repi(i, 1, n) in(&k[i]);

    repi(i, 1, n){
        repi(j, i + 1, n){
            E.push_back(edge((ll)i, (ll)j, dist(i, j)));
        }
    }
    repi(i, 1, n){
        E.push_back(edge(n + 1, i, c[i]));
    }
    sort(E.begin(), E.end(), cmp);

    repi(i, 1, n) fa[i] = i;
    int len = E.size(), cn = 0;
    ll ans = 0, v = 0;
    repi(i, 0, len - 1){
        if(cn == n) break;
        if(getfa(E[i].s) != getfa(E[i].t)){
            choo.push_back(i);
            fa[getfa(E[i].s)] = getfa(E[i].t);
            cn++; ans += E[i].d;
            if(E[i].s == n + 1) v++;
        }
    }

    printf("%I64d\n%I64d\n", ans, v);
    repi(i, 0, n - 1){
        if(E[choo[i]].s == n + 1) printf("%I64d ", E[choo[i]].t);
    }
    printf("\n%I64d\n", n - v);
    repi(i, 0, n - 1){
        if(E[choo[i]].s != n + 1) printf("%I64d %I64d\n", E[choo[i]].s, E[choo[i]].t);
    }

    return 0;
}