#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll INF = 0x3f3f3f3f3f3f3f3fll;
const int maxn = 6e5+5;
const ll mod = 1e9+7;

struct Tree{
    int mi, lz, pos, cnt;
}T[maxn<<2];
#define mid ((l+r)>>1)
#define ls (u<<1)
#define rs (u<<1|1)
inline void build(int u,int l,int r){
    T[u].lz = T[u].mi = 0;
    T[u].pos = r;
    T[u].cnt = r-l+1;
    if(l == r) return;
    build(ls,l,mid), build(rs,mid+1,r);
}
inline void pushup(int u){
    if(T[ls].mi == T[rs].mi){
        T[u].mi = T[ls].mi;
        T[u].cnt = T[ls].cnt + T[rs].cnt;
        T[u].pos = T[rs].pos;
    }else{
        int lz = T[u].lz;
        T[u] = (T[ls].mi > T[rs].mi) ? T[rs] : T[ls];
        T[u].lz = lz;
    }
}
inline void pushdown(int u){
    if(T[u].lz){
        T[ls].lz += T[u].lz, T[ls].mi += T[u].lz;
        T[rs].lz += T[u].lz, T[rs].mi += T[u].lz;
        T[u].lz = 0;
    }
}
inline void change(int u,int l,int r,int L,int R,int v){
    if(L<=l&&r<=R){
        T[u].lz += v;
        T[u].mi += v;
        return;
    }
    pushdown(u);
    if(L<=mid) change(ls,l,mid,L,R,v);
    if(R>mid) change(rs,mid+1,r,L,R,v);
    pushup(u);
}
Tree nod;
inline void query(int u,int l,int r,int L,int R){
    if(L<=l&&r<=R){
        if(T[u].mi < nod.mi){
            nod = T[u];
        }else if(T[u].mi == nod.mi){
            nod.pos = max(nod.pos, T[u].pos);
            nod.cnt += T[u].cnt;
        }
        return;
    }
    pushdown(u);
    if(L<=mid) query(ls,l,mid,L,R);
    if(R>mid) query(rs,mid+1,r,L,R);
    pushup(u);
}
int n, m, N;
char s[maxn];
int S[maxn];

inline Tree query(int L, int R){
    nod.mi = INF;
    query(1,1,N,L,R);
    return nod;
}
void dbg(){
    for(int i = 1; i <= N; i++)
        printf("%d ", query(i,i).mi);
    puts("");
}
int main(){
    scanf("%d%d", &n, &m);
    scanf("%s", s+1);
    N = 2*n;
    build(1,1,N);
    for(int i = 1; i <= n; i++){
        S[i] = S[i+n] = (s[i] == '(' ? 1 : -1);
        change(1,1,N,i,N,S[i]);
        change(1,1,N,i+n,N,S[i+n]);
//        printf("%d ", query(i,i).mi);
    }
    if(query(n,n).mi != 0){
        puts("0\n1 1");
        return 0;
    }
    int ans = 0;
    int rl = 1, rr = 1;

    for(int i = 1; i <= n; i++){
        Tree tmp = query(i,i+n-1);
        if(S[i] == 1){
            if(tmp.mi == 0) {
                if(tmp.cnt > ans){
                    ans = tmp.cnt;
                    rl = rr = 1;
                }
            }
        }else{
            if(tmp.mi == -1){
                change(1,1,N,i,tmp.pos,2);
                Tree tmp2 = query(i,i+n-1);
                assert(tmp2.mi == 0);
                if(tmp2.cnt > ans){
                    ans = tmp2.cnt;
                    rl = i, rr = tmp.pos+1;
                }
                change(1,1,N,i,tmp.pos,-2);
            }else if(tmp.mi == -2){
                change(1,1,N,i,tmp.pos,1);
                Tree tmp2 = query(i,i+n-1);
                assert(tmp2.mi == -1);
                change(1,1,N,i,tmp2.pos,1);
                if(tmp.pos < tmp2.pos)
                    change(1,1,N,tmp.pos+1,tmp2.pos,1);
                Tree tmp3 = query(i,i+n-1);
                assert(tmp3.mi == 0);
                if(tmp3.cnt > ans){
                    ans = tmp3.cnt;
                    rl = i, rr = tmp2.pos+1;
                }
                change(1,1,N,i,tmp2.pos,-2);
            }
        }
        change(1,1,N,i,N,-S[i]);
    }
    if(rl > n) rl -= n;
    if(rr > n) rr -= n;
    printf("%d\n%d %d\n", ans, rl, rr);
    return 0;
}
