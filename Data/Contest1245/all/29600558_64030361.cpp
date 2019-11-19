#include <iostream>
#include <algorithm>
#include <cstdlib>

const int N = 2000; 

using ll = long long;

int abs(int x) {
    return x < 0 ? -x : x;
}

int x[N + 5], y[N + 5]; 
int c[N + 5], k[N + 5]; 
int n; 
int is[N + 5], ini[N + 5];
ll toc[N + 5];
int rc[N + 5], rt, pr[N + 5][2], pt;

struct EE {
    int a, b;
    ll val;

    bool operator < (const EE &o) {
        return val < o.val;
    }
} Ee[(N + 5) * (N + 5) + 5]; 
int Etot; 

int f[N + 5];

int find(int x) {
    if (f[x] < 0) return x;
    f[x] = find(f[x]);
    return f[x];
}

void merge(int x, int y) {
    x = find(x); 
    y = find(y); 

    if (x == y) return ;
    if (f[x] > f[y]) std::swap(x, y);
    f[x] += f[y]; 
    f[y] = x;

    return ;
}

int main() {

    std::cin >> n; 
    for (int i = 1; i <= n + 1; i ++)
        f[i] = -1;
    for (int i = 1; i <= n; i ++)   
        std::cin >> x[i] >> y[i]; 

    for (int i = 1; i <= n; i ++) 
        std::cin >> c[i]; 
    for (int i = 1; i <= n; i ++)   
        std::cin >> k[i]; 

    for (int i = 1; i <= n; i ++) Ee[++ Etot].a = n + 1, Ee[Etot].b = i, Ee[Etot].val = c[i];
    for (int i = 1; i <= n; i ++)
        for (int j = i + 1; j <= n; j ++) {
            Ee[++ Etot].a = i, Ee[Etot].b = j; 
            Ee[Etot].val = (ll) (k[i] + k[j]) * (abs(x[i] - x[j]) + abs(y[i] - y[j]));
        }
    
    ll cost = 0;
    std::sort(Ee + 1, Ee + Etot + 1);

    for (int i = 1; i <= Etot; i ++) {
        int a = Ee[i].a, b = Ee[i].b;
        ll val = Ee[i].val;
        //a = find(a), b = find(b); 
        if (find(a) == find(b)) continue ;
        merge(a, b);
        cost += val;
        if (a == n + 1) rc[++ rt] = b; 
        else pr[++ pt][0] = a, pr[pt][1] = b;
    }

    std::cout << cost << std::endl;
    std::cout << rt << std::endl;
    for (int i = 1; i <= rt; i ++) 
        std::cout << rc[i] << " ";
    std::cout << std::endl << pt << std::endl; 
    for (int i = 1; i <= pt; i ++) 
        std::cout << pr[i][0] << " " << pr[i][1] << std::endl;

    return 0;
}