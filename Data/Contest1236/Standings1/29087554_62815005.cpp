#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <set>

using namespace std;

#define X first
#define Y second
#define mp make_pair
#define pb push_back
typedef long long ll;
typedef pair <int, int> pii;
typedef pair <int, pii> pip;
typedef pair <pii, int> ppi;

const int INF=0x3f3f3f3f;
const int N=1e5+5;

int n, m, k;
int u=0, d, r, l=0;
int x=1, y=1;
set <int> red[N], stup[N];

void load() {
    scanf("%d %d %d", &n, &m, &k);
    d=n+1; r=m+1;
    for (int i=0; i<k; ++i) {
        int a, b;
        scanf("%d %d", &a, &b);
        red[a].insert(b);
        stup[b].insert(a);
    }
}

void solve() {
    int br=1, boo=0; //1 desno, 2 dolje, 3 lijevo, 4 gore
    ll cnt=1;
    while (1) {
        if (br==1) {
            int ny=r-1;
            auto it=red[x].upper_bound(y);
            if (it!=red[x].end()) ny=min(ny, *it-1);
            if (ny==y && (x!=1 || y!=1)) break;
            cnt+=(ll)(ny-y);
            u=x;
            y=ny;
        }
        else if (br==2) {
            int nx=d-1;
            auto it=stup[y].upper_bound(x);
            if (it!=stup[y].end()) nx=min(nx, *it-1);
            if (nx==x) break;
            cnt+=(ll)(nx-x);
            r=y;
            x=nx;
        }
        else if (br==3) {
            int ny=l+1;
            auto it=red[x].upper_bound(y);
            if (it!=red[x].begin()) {
                --it;
                ny=max(ny, *it+1);
            }
            if (ny==y) break;
            cnt+=(ll)(y-ny);
            d=x;
            y=ny;
        }
        else {
            int nx=u+1;
            auto it=stup[y].upper_bound(x);
            if (it!=stup[y].begin()) {
                --it;
                nx=max(nx, *it+1);
            }
            if (nx==x) break;
            cnt+=(ll)(x-nx);
            l=y;
            x=nx;
        }
//        printf("(%d, %d), boo = %d\n", x, y, boo);
//        system("pause");
        br=br+1;
        if (br==5) br=1;
        //if (cnt>k) break;
    }
    //printf("cnt == %d\n", cnt);
    cnt=(ll)n*(ll)m-cnt;
    if (cnt!=(ll)k) printf("No\n");
    else printf("Yes\n");
}

int main() {
    load();
    solve();
    return 0;
}
