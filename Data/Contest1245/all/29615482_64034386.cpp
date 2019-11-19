#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef double db;
const int mod =1e9+7;
const int maxn = 1e5+100;
const db eps = 1e-6;

const int N =4001000;
template<typename Type>
struct Krustal
{
    int uf_node[N]; //每个节点
    int uf_rank[N]; //树的高度

//初始化n个节点
    void uf_init(int n)
    {
        for (int i = 0; i <= n; i++)
        {
            uf_node[i] = i;
            uf_rank[i] = 0;
        }
    }
//查找当前元素所在树的根节点(代表元素)
    int uf_find(int x)
    {
        if (x == uf_node[x])
            return x;
        return uf_node[x] = uf_find(uf_node[x]); //在第一次查找时，将节点直连到根节点
    }
//合并元素x， y所处的集合
    void uf_unite(int x, int y)
    {
        //查找到x，y的根节点
        x = uf_find(x);
        y = uf_find(y);
        if (x == y)
            return;
        //ans--;
        //判断两棵树的高度，然后在决定谁为子树
        if (uf_rank[x] < uf_rank[y])
        {
            uf_node[x] = y;
        }
        else
        {
            uf_node[y] = x;
            if (uf_rank[x] == uf_rank[y])
                uf_rank[x]++;
        }
    }
//判断x，y是属于同一个集合
    bool uf_same(int x, int y)
    {
        return uf_find(x) == uf_find(y);
    }
//判断连通块数量
    int uf_blocknum(int n)
    {
        int ans=0;
        for (int i = 1; i <= n; i++)//判断只有一个连通块
            if (uf_node[i] == i)
                ans++;
        return ans;
    }
    struct poin
    {
        int x,y;
        poin(){}
        poin(int xx, int yy){x = xx; y = yy;}
    };

    vector<poin> ans;
    struct node
    {
        int u, v;
        Type k;
        node(int u, int v, Type k):u(u),v(v),k(k){}
        bool operator < (const node&b) const
        {
            return this->k<b.k;//数组升序，小的靠前
        }
    };
    int n;
    vector<node>edge;
//加边，无需双向加边
    void add_edge(int u,int v,Type k)
    {
        edge.push_back(node(u,v,k));
    }
    void init(int n)
    {
        this->n=n;
        edge.clear();
        ans.clear();
        uf_init(n+1);
    }

    Type krustal()
    {
        sort(edge.begin(), edge.end());
        Type sum = 0;
        int j, i;
        for (i = 0, j = 0; i < n - 1;)
        {
            if (j ==(int) edge.size())
                break;
            int u, v;
            Type k;
            u = edge[j].u;
            v = edge[j].v;
            k = edge[j].k;
            if (!uf_same(u, v))
            {
                sum += k;
                i++;
                uf_unite(u, v);
                ans.push_back(poin(u,v));
            }
            j++;
        }
        return sum;
    }
};
Krustal<LL>G;

struct point
{
    int x,y;
    point(){}
    point(int xx, int yy){x = xx; y = yy;}
}p[2200];
 bool cmp(point A, point B)
    {
        if(A.x==B.x)
            return A.y<B.y;
        return A.x<B.x;
    }
LL sum(point a, point b)
{
    return 1ll * (abs(a.x-b.x)+abs(a.y-b.y));
}
LL c[2200], k[2200];
vector < int > num;

vector<point> ank;
int main()
{
    int n;
    scanf("%d", &n);
    num.clear();
    G.init(n+1);
    for(int i = 1; i <= n; i++)
    {
        scanf("%d%d", &p[i].x, &p[i].y);
    }
    for(int i = 1; i <=n;i++)
    {
        scanf("%lld", &c[i]);
    }
    for(int i = 1; i <= n;i++)
        scanf("%lld", &k[i]);
    for(int i = 1; i <= n; i++)
    {
        for(int j = i+1; j <= n; j++)
        {
            G.add_edge(i,j,(k[i]+k[j])*sum(p[i],p[j]));
        }
    }
    for(int i = 1; i <= n; i++)
    {
        G.add_edge(0,i,c[i]);
    }
    LL ansa = G.krustal();
    printf("%lld\n", ansa);
    int siz = G.ans.size();
    for(int i = 0; i < siz; i++)
    {
        if(G.ans[i].x==0)
        {
            num.push_back(G.ans[i].y);
        }
        else if(G.ans[i].y==0)
        {
            num.push_back(G.ans[i].x);
        }
        else
        {
            ank.push_back(point(G.ans[i].x,G.ans[i].y));
        }
        //printf("%d, %d\n", G.ans[i].x, G.ans[i].y);
    }
    siz = num.size();
    sort(num.begin(), num.end());
    printf("%d\n", siz);
    for(int i = 0; i < siz; i++)
    {
        printf("%d ", num[i]);
    }
    printf("\n");
    siz = ank.size();
    sort(ank.begin(), ank.end(),cmp);
    printf("%d\n", siz);
    for(int i = 0; i < siz; i++)
    {
        printf("%d %d\n", ank[i].x, ank[i].y);
    }



    return 0;
}
