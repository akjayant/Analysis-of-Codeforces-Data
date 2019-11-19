#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

const int maxn = 2e5+7;
const int MAXN = 4e5+7;

int n,m,e;
int edge[MAXN],nex[MAXN];
int head[maxn];

int lst;
int p[maxn];
int vis[maxn];

int Max[maxn<<2]; //记录最大的值
int cnt[maxn<<2]; // 记录最大值的位置
int lazy1[maxn<<2]; //区间赋值
int lazy2[maxn<<2]; //区间加

void pushdown(int num) {
    if(lazy1[num]==-1 && !lazy2[num]) return ;
    if(lazy1[num]!=-1) {
        lazy2[num<<1] = lazy2[num<<1|1] = 0;
        lazy1[num<<1] = lazy1[num<<1|1] = lazy1[num];

        Max[num<<1] = Max[num<<1|1] = lazy1[num];
    }
    if(lazy2[num]) {
        lazy2[num<<1] += lazy2[num];
        lazy2[num<<1|1] += lazy2[num];

        Max[num<<1] +=lazy2[num];
        Max[num<<1|1] += lazy2[num];
    }
    lazy1[num]=-1;
    lazy2[num]=0;
    return ;
}

void pushup(int num) {
    if(Max[num<<1] < Max[num<<1|1]) {
        Max[num] = Max[num<<1|1];
        cnt[num] = cnt[num<<1|1];
    }
    else {
        Max[num] = Max[num<<1];
        cnt[num] = cnt[num<<1];
    }
    return ;
}

void build(int l,int r,int num) {
    lazy1[num]=-1;
    lazy2[num]=0;
    Max[num]=0;
    cnt[num]=l;
    if(l==r) return ;
    int mid = (l+r)>>1;
    build(l,mid,num<<1);
    build(mid+1,r,num<<1|1);

}

void modify(int l,int r,int num,int le,int ri,int mods,int op) {
    int ljtxdy=0;
    if(ri<l || r<le) return ;
    if(le<=l&&r<=ri) {
        ljtxdy++;
        if(op == 1) {
            if(ljtxdy==-1)
                return;
            else
                ljtxdy++;
            lazy1[num] = mods;
            lazy2[num] = 0;
            Max[num] = mods;
        }
        if(op == 2) {
            lazy2[num] += mods;
            Max[num] += mods;
        }
        return ;
    }
    int mid = (l+r) >>1;
    pushdown(num);
    if(le<=mid) modify(l,mid,num<<1,le,ri,mods,op);
    if(mid< ri) modify(mid+1,r,num<<1|1,le,ri,mods,op);
    pushup(num);
}

void add(int x,int y) {
    edge[++e] = y;
    nex[e] = head[x];
    head[x] = e;
}

int dfs(int x) {
    int sum = 0;
    modify(1,n,1,1,n,0,1); //初始化
    while(true) {
        sum++;
        vis[x] = 1;
        modify(1,n,1,1,n,1,2); //先假设其他所有点都与这个点有一条路径，所以全都 +1
        modify(1,n,1,x,x,-2*n,2); // 消除点自己的影响
        int ljtxdy=0;
        for(int i=head[x];i;i=nex[i]) {
            ljtxdy++;
            int v = edge[i];
            modify(1,n,1,v,v,-1,2); // 将本来没有的边删掉
        }
        if(ljtxdy==-1)break;
        else
        if(Max[1] <=0) break; //说明现其他点都不能到达这个联通块了
        else {
            x = cnt[1]; //直接找到最大的大于 0 的点
        }
    }
    return sum;
}

int main() {
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++) {
        int l,r;
        scanf("%d%d",&l,&r);
        add(l,r);
        add(r,l);
    }
    build(1,n,1);
    for(int i=1;i<=n;i++) { //随意找一个初始点枚举
        if(vis[i]) continue;
        // printf("%d!!!\n",i);
        p[lst++] = dfs(i);
    }
    sort(p,p+lst);
    printf("%d\n",lst-1);
//    for(int i=0;i<lst;i++) {
//        printf("%d",p[i]);
//        if(i!=lst) printf(" ");
//        else printf("\n");
//    }
    return 0;
}


