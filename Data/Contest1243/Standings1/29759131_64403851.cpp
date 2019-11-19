// Add a number in range
// Query min of range, the leftmost/rightmost array index where number <= target

// AC CF


// Bismillahir Rahmanir Rahim
#include <bits/stdc++.h>

using namespace std;

#define double long double
#define Long long long
#define EPS 1e-12
#define PI acos(-1.0)

#define MAX 300000
#define MOD 1000000007

#define POS_INF (1LL << 60)
#define NEG_INF (-(1LL << 60))

#define RIGHT_MOST_INDEX (1 << 30)
#define LEFT_MOST_INDEX (-(1 << 30))

#define MEMSET(x,y) memset(x, y, sizeof(x))
#define PB push_back
#define MP make_pair
#define SORT(A) sort(A.begin(), A.end());
#define REVERSE(A) reverse(A.begin(), A.end());

Long seg_tree[MAX * 10 + 9];
Long lazy[MAX * 10 + 9];

void init_tree(int node, int beg, int end)
{
    if(beg == end)
    {
        seg_tree[node] = 0;
        lazy[node] = 0;
        return;
    }

    int mid = (beg + end) >> 1;

    init_tree((node << 1), beg, mid);
    init_tree((node << 1) | 1, mid + 1, end);

    seg_tree[node] = 0;
    lazy[node] = 0;
}

inline void split_node(int node)
{
    if(lazy[node] == 0) return;

    seg_tree[(node << 1)] += lazy[node];
    lazy[(node << 1)] += lazy[node];

    seg_tree[(node << 1) | 1] += lazy[node];
    lazy[(node << 1) | 1] += lazy[node];

    lazy[node] = 0;
}

inline void merge_node(int node)
{
    seg_tree[node] = min(seg_tree[(node << 1)], seg_tree[(node << 1) | 1]);
}

void update(int node, int beg, int end, int i, int j, Long value)
{
    if(beg > j || end < i) return;
    if(beg >= i && end <= j)
    {
        seg_tree[node] += value;
        lazy[node] += value;
        return ;
    }

    split_node(node);
    int mid = (beg + end) >> 1;

    update((node << 1), beg, mid, i, j, value);
    update((node << 1) | 1, mid + 1, end, i, j, value);
    merge_node(node);
}

int query_leftmost(int node, int beg, int end, int i, int j, Long target)
{
    if(i > end || j < beg) return RIGHT_MOST_INDEX;
    if(seg_tree[node] > target) return RIGHT_MOST_INDEX;
    if(beg == end) return beg;

    split_node(node);

    int mid = (beg + end) >> 1;

    int ind = query_leftmost((node << 1), beg, mid, i, j, target);
    if(ind != RIGHT_MOST_INDEX) return ind;

    return query_leftmost(((node << 1) | 1), mid + 1, end, i, j, target);
}

int query_rightmost(int node, int beg, int end, int i, int j, Long target)
{
    if(i > end || j < beg) return LEFT_MOST_INDEX;
    if(seg_tree[node] > target) return LEFT_MOST_INDEX;
    if(beg == end) return beg;

    split_node(node);

    int mid = (beg + end) >> 1;

    int ind = query_rightmost(((node << 1) | 1), mid + 1, end, i, j, target);
    if(ind != LEFT_MOST_INDEX) return ind;

    return query_rightmost((node << 1), beg, mid, i, j, target);
}

Long query(int node, int beg, int end, int i, int j)
{
    if(i > end || j < beg) return POS_INF;
    if(beg >= i && end <= j) return seg_tree[node];

    split_node(node);
    int mid = (beg + end) >> 1;

    Long leftnode = query((node << 1), beg, mid, i, j);
    Long rightnode = query(((node << 1) | 1), mid + 1, end, i, j);

    return min(leftnode, rightnode);
}

vector<Long> adj[MAX+9];
queue<Long> qu;

int main()
{
    Long i,j,k,l,n,m=0,tot,temp,curr,val,prev,a,b,c,t,ans,child,flag,x,y,siz,w,h,d,ii,jj,xx,yy,ind,len,max_n,q;

    cin>>n>>m;
    for(i=1; i<=n; i++) adj[i].PB(0);
    for(i=1; i<=n; i++) adj[i].PB(n+1);

    for(i=1; i<=m; i++)
    {
        scanf("%lld%lld", &j, &k);
        adj[j].PB(k);
        adj[k].PB(j);
    }

    for(i=1; i<=n; i++) SORT(adj[i]);

    init_tree(1, 1, n);
    ans = -1;
    for(i=1; i<=n; i++)
    {
        if(query(1, 1, n, i, i) == 0)
        {
            ans++;
            qu.push(i);
            update(1, 1, n, i, i, 1);

            //cout<<i<<" new\n";

            while(!qu.empty())
            {
                curr = qu.front();
                qu.pop();

                for(j=1; j<adj[curr].size(); j++)
                {
                    a = adj[curr][j-1];
                    b = adj[curr][j];

                    //cout<<a<<" ff "<<b<<endl;

                    while(1)
                    {
                        flag = 0;
                        child = query_leftmost(1, 1, n, a+1, b-1, 0);
                        if(child != RIGHT_MOST_INDEX)
                        {
                            if(query(1, 1, n, child, child) == 0)
                            {
                                //cout<<"take "<<child<<endl;
                                flag = 1;
                                qu.push(child);
                                update(1, 1, n, child, child, 1);
                            }
                        }

                        if(flag == 0) break;
                    }
                }
            }
        }
    }

    cout<<ans<<endl;
}
